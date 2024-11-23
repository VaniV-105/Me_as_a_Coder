#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    stack<int> s;
    s.push(startNode);
    while (!s.empty()) {
        cout << "Stack: ";
            stack<int> temp = s;
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
        cout<<endl;
        int currentNode = s.top();
        s.pop();
        if (!visited[currentNode]) {
            cout << "Visited: " << currentNode << endl;
            visited[currentNode] = true;
            cout << endl;
            for (int neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(vertices);

    cout << "Enter edges (format: u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }
    vector<bool> visited(vertices, false);
    int start;
    cout << "Enter the starting vertex for DFS: ";
    cin >> start;
    dfs(adjList, start, visited);
    return 0;
}
