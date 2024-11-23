#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
void addEdge(vector<vector<int>> & a,int u,int v){
    a[u].emplace_back(v);
}
void BFS(vector<vector<int>> & a,int start, vector<bool> & visited){
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int current = q.front();
        cout<<"Visited:"<<current<<endl;
        q.pop();
        for(int i : a[current]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
void DFS(vector<vector<int>> & a,int start, vector<bool> & visited){
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int current = s.top();
        s.pop();
        if(!visited[current]){
            cout<<"Visited:"<<current<<endl;
            visited[current]=true;
        }
        for(int i : a[current]){
            if(!visited[i]){
                s.push(i);
            }
        }
    }
}
int main(){
    vector<vector<int>> adj(5);
    addEdge(adj,0,1);
    addEdge(adj,2,3);
    addEdge(adj,1,2);
    addEdge(adj,0,2);
    addEdge(adj,3,4);
    addEdge(adj,2,4);
    vector<bool> visited(5,false);
    cout<<"BFS"<<endl;
    BFS(adj,0,visited);
    cout<<"DFS"<<endl;
    vector<bool> v(5,false);
    DFS(adj,0,v);
    return 0;
}