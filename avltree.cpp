#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
};

// Get height of node
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Get balance factor
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Create new node
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert node and balance
Node* insert(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // No duplicates

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Get node with minimum key in subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete node and balance
Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // One or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            delete temp;
        } else {
            // Two children
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Preorder
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Main menu
int main() {
    Node* root = NULL;
    int choice, key;
    do {
        cout << "\nAVL Tree Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                root = insert(root, key);
                cout << "Inserted.\n";
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                cout << "Deleted (if present).\n";
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
