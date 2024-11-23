#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>>& a,int u,int v){
    a[u].emplace_back(v);
}
void bfs(vector<vector<int>>& a,int source,vector<bool>& v){
    queue<int> q;
    v[source]=true;
    q.push(source);
    while(!q.empty()){
        cout<<"Queue:";
        queue<int> temp = q;
        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
        int current = q.front();
        cout<<"Visited:"<<current<<endl;
        q.pop();
        for(int i:a[current]){
            if(!v[i]){
                v[i]=true;
                q.push(i);
            }
        }

    }
}