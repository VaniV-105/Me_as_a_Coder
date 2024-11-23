#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
class Graph {
private:
    int V;//Vertices count
    vector<vector<pair<int, int>>> adjList;//adj[v1]=pair<v2,w>
public:
    Graph(int n) : V(n), adjList(n) {}
    void addEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);//Undirected graph
        adjList[v].emplace_back(u, w);
    }
    void printGraph(){
        cout<<"Vertex\tAdjacent"<<endl;
        for(int i=0;i<V;i++){
            cout<<i<<"\t";
            for(const auto &edge : adjList[i] ){
                cout<<edge.first<<" ";
            }
            cout<<endl;
        }
    }
    vector<int> dijkstra(int source) {
        vector<int> dist(V, numeric_limits<int>::max());
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
int main() {
    int vertices, edges;
    cout<<"Enter no of vertices:";
    cin >> vertices;
    cout<<"Enter no of edges:";
    cin>>edges;
    Graph graph(vertices);
    cout<<"Enter edges in format (start,end,weight):";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    graph.printGraph();
    cout<<"Enter source:";
    int source;
    cin >> source;
    vector<int> shortestDistances = graph.dijkstra(source);
    for (int i = 0; i < vertices; ++i) {
        if (shortestDistances[i] == numeric_limits<int>::max()) {
            cout << "Vertex " << i << ": unreachable" << endl;
        } else {
            cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
        }
    }
    return 0;
}
