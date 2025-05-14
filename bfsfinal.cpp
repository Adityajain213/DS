#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int numvertices =0;

void creategraph(int vertices){
    numvertices =vertices;
    adj.assign(vertices,vector<int>());
    cout<<"graph created with: "<<vertices<<endl;
}

void addedges(int src,int dest){
adj[src].push_back(dest);
adj[dest].push_back(src);
}

void displaylist(){
    for(int i=0;i<numvertices;i++){
        cout<<i<<":";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

vector<int> bfs(int src){
    vector<int> ans;
   visited.assign(numvertices,false);
   queue<int> q;
   q.push(src);
   while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for(int j=0;j<adj[node].size();j++){
        if(!visited[adj[node][j]]){
            q.push(adj[node][j]);
            visited[adj[node][j]]=true;
        }
    }
   }
   return ans;
}
int main() {
    int choice, src, dest, start, vertices;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Create Graph\n";
        cout << "2. Add Edge\n";
        cout << "3. Display Graph\n";
        cout << "4. BFS Traversal\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of vertices: ";
                cin >> vertices;
                creategraph(vertices);
                break;

            case 2:
                cout << "Enter source and destination: ";
                cin >> src >> dest;
                addedges(src, dest);
                break;

            case 3:
                displaylist();
                break;

            case 4:
                cout << "Enter starting vertex for BFS: ";
                cin >> start;
                bfs(start);
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