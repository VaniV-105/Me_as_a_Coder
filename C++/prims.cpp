#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
using namespace std;
class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int n) : V(n), adjList(n) {}
    void addEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }
    vector<pair<int, int>> primMST(int startVertex) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(V, false);
        vector<pair<int, int>> mstEdges(V, {-1, numeric_limits<int>::max()});
        pq.push({0, startVertex});
        mstEdges[startVertex] = {-1, 0};
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (inMST[u])
                continue;
            inMST[u] = true;
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (!inMST[v] && weight < mstEdges[v].second) {
                    mstEdges[v] = {u, weight};
                    pq.push({weight, v});
                }
            }
        }
        return mstEdges;
    }
};
int main() {
    int vertices, edges;
    cout << "Enter no of vertices:";
    cin >> vertices;
    cout << "Enter no of edges:";
    cin >> edges;
    Graph graph(vertices);
    cout << "Enter the edges (source,dest,weight):";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    cout << "Enter Start Vertex:";
    int startVertex;
    cin >> startVertex;
    vector<pair<int, int>> mstEdges = graph.primMST(startVertex);
    cout << "Minimum Spanning Tree (MST) Edges:" << endl;
    for (int i = 0; i < vertices; ++i) {
        if (mstEdges[i].first != -1) {
            cout << mstEdges[i].first << " - " << i << " (Weight: " << mstEdges[i].second << ")" << endl;
        }
    }
    return 0;
}
