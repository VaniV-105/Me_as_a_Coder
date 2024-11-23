#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;
class Graph{
    int V;
    vector<vector<pair<int,int>>> adjList;
    public:
        Graph(int n):V(n),adjList(n){}
        void addEdge(int u,int v,int w){
            adjList[u].emplace_back(v,w);
            adjList[v].emplace_back(u,w);
        }
        void printGraph(){
            cout<<"Vertex\tAdjacent"<<endl;
            for(int i=0;i<V;i++){
                cout<<i<<"\t";
                for(const auto & a:adjList[i]){
                    cout<<a.first<<" ";
                }
                cout<<endl;
            }
        }
        vector<int> dijkstra(int source){
            vector<int> dist(V,numeric_limits<int>::max());
            dist[source]=0;
            priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,source});
            while(!pq.empty()){
                int u=pq.top().second;
                int d=pq.top().first;
                pq.pop();
                if(d>dist[u])
                    continue;
                for(const auto & edge : adjList[u]){
                    int v=edge.first;
                    int w=edge.second;
                    if(dist[u]+w<dist[v]){
                        dist[v]=dist[u]+w;
                        pq.push({dist[v],v});
                    }
                }
            }
            return dist;
        }
};
int main(){
    cout<<"Enter no of vertices:";
    int vertices,edges;
    cin>>vertices;
    cout<<"Enter no of edges:";
    cin>>edges;
    Graph g(vertices);
    cout<<"Enter edges in the form u v w:"<<endl;
    int u,v,w;
    for(int i=0;i<vertices;i++){
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    g.printGraph();
    int source;
    cout<<"Enter source:";
    cin>>source;
    vector<int> sd = g.dijkstra(source);
    for(int i=0;i<vertices;++i){
        if(sd[i]==numeric_limits<int>::max())
            cout<<"Vertex "<<i<<": Unreachable"<<endl;
        else    
            cout<<"Vertex "<<i<<":"<<sd[i]<<endl;
    }
    return 0;
}