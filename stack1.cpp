#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

void checkparenthesis(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (st.empty() || 
                (c == ')' && st.top() != '(') || 
                (c == '}' && st.top() != '{') || 
                (c == ']' && st.top() != '[')) {
                cout << "Invalid mismatch" << endl;
                return;
            }
            st.pop();
        }
    }
    if (!st.empty()) {
        cout << "Invalid mismatch" << endl;
    } else {
        cout << "Valid" << endl;
    }
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    return 0;
}

void infix_to_postfix(const string& s1) {
    stack<char> s12;
    string ans = "";
    for (char ch : s1) {
        if (isalnum(ch)) {
            ans += ch;
        } else if (ch == '(') {
            s12.push(ch);
        } else if (ch == ')') {
            while (!s12.empty() && s12.top() != '(') {
                ans += s12.top();
                s12.pop();
            }
            if (!s12.empty()) s12.pop();
        } else {
            while (!s12.empty() && precedence(ch) <= precedence(s12.top())) {
                ans += s12.top();
                s12.pop();
            }
            s12.push(ch);
        }
    }
    while (!s12.empty()) {
        ans += s12.top();
        s12.pop();
    }

    cout << "Postfix: " << ans << endl;
}

int postfixevaluation(const string& s2) {
    stack<int> p;
    for (char ch : s2) {
        if (isdigit(ch)) {
            p.push(ch - '0');
        } else {
            if (p.size() < 2) {
                cout << "Error: insufficient operands\n";
                return 0;
            }
            int b = p.top(); p.pop();
            int a = p.top(); p.pop();
            int res;
            switch (ch) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                default: cout << "Unsupported operator\n"; return 0;
            }
            p.push(res);
        }
    }
    return p.top();
}

string postfix_to_infix(const string& s3) {
    stack<string> st;
    for (char ch : s3) {
        if (isalnum(ch)) {
            st.push(string(1, ch));
        } else {
            if (st.size() < 2) return "Error";
            string second = st.top(); st.pop();
            string first = st.top(); st.pop();
            st.push("(" + first + ch + second + ")");
        }
    }
    return st.top();
}

int main() {
    int choice;
    string s1, s2, s3, s;

    do {
        cout << "\n==== Menu ====\n";
        cout << "1. Matching Parenthesis\n";
        cout << "2. Infix to Postfix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Postfix to Infix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter expression with parentheses: ";
                cin >> s;
                checkparenthesis(s);
                break;
            case 2:
                cout << "Enter infix expression: ";
                cin >> s1;
                infix_to_postfix(s1);
                break;
            case 3:
                cout << "Enter postfix expression: ";
                cin >> s2;
                cout << "Result: " << postfixevaluation(s2) << endl;
                break;
            case 4:
                cout << "Enter postfix expression: ";
                cin >> s3;
                cout << "Result: " << postfix_to_infix(s3) << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
