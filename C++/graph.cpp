#include <iostream>
using namespace std;
#include <list>
class Graph{
    public:
        int numVertices;
        list<int> *adjLists;

        Graph(int V){
            numVertices = V;
            adjLists = new list<int>[V];
        }

        void addEdge(int src,int dest){
            adjLists[src].push_back(dest);
        }

        void printGraph(){
            for(int i=0;i<numVertices;i++){
                cout<<"Adjacency list of vertex "<<i<<"\n head";

                for(auto x : adjLists[i]){
                    cout <<  "->"<<x;
                }
                printf("\n");
            }
        }
};
int main(){
    int v,e;
    cout<<"Enter the no of vertices:";
    cin>>v;
    Graph g(v);
    cout<<"Enter the no of edges:";
    cin>>e;
    int s,d;
    for(int i=1;i<=e;i++){
        cout<<"Edge "<<i<<" Src, Dest :"<<endl;
        cin>>s>>d;
        g.addEdge(s,d);
    }
    
    g.printGraph();

    return 0;
}