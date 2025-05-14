#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int numvertices = 0;

void createGraph(int vertices) {
    numvertices = vertices;
    adj.assign(numvertices, vector<int>());
    visited.assign(numvertices, false);
}

void addEdge(int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

vector<int> dfs(int src) {
    stack<int> st;
    st.push(src);
    visited[src] = true;
    vector<int> ans;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        ans.push_back(node);
        
        // Traverse all neighbors and push unvisited ones onto the stack
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return ans;
}

int main() {
    int choice, src, dest, start, vertices;
    
    do {
        cout << "\n1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. DFS Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of vertices: ";
                cin >> vertices;
                createGraph(vertices);
                break;

            case 2:
                cout << "Enter source and destination: ";
                cin >> src >> dest;
                addEdge(src, dest);
                break;

            case 3:
                cout << "Enter starting vertex for DFS: ";
                cin >> start;
                visited.assign(numvertices, false); // Reset visited array before DFS
                {
                    vector<int> dfsResult = dfs(start);  // Initialize dfsResult inside block scope
                    cout << "DFS Traversal: ";
                    for (int node : dfsResult) {
                        cout << node << " ";
                    }
                    cout << endl;
                }
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
