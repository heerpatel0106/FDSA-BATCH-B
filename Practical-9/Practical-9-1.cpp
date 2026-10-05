#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void DFS(int node,vector<vector<int>>&graph,vector<bool>&visited){
    visited[node]=true;
    cout<<node<<" ";

    for(int next:graph[node]){
        if(!visited[next])
            DFS(next,graph,visited);
    }
}

void BFS(int start,vector<vector<int>>&graph,int n){
    vector<bool>visited(n,false);
    queue<int>q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int next:graph[node]){
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<int>>graph(n);

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cin>>start;

    vector<bool>visited(n,false);

    cout<<"DFS: ";
    DFS(start,graph,visited);

    cout<<endl<<"BFS: ";
    BFS(start,graph,n);

    return 0;
}