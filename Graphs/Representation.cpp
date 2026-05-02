#include<bits/stdc++.h>
using namespace std;

int main(){
//Adjacency Matrix Representation
    int n , m;
    cin>>n>>m;
    int adj[n+1][m+1];//1 based indexing
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v; //edge from u to v
        adj[u][v] = 1; //marking the presence of an edge
        adj[v][u] = 1; //marking the presence of an edge (for undirected graph)
    }
    

//List Representation
    int n1 , m2;
    cin>>n1>>m2;
    vector<int>adj1[n1+1];
    for(int i = 0; i<m2; i++){
        int u, v;
        cin>>u>>v; //edge from u to v
        adj1[u].push_back(v); //marking the presence of an edge
        adj1[v].push_back(u); //marking the presence of an edge (for undirected graph only otherwise no need )
    }
    return 0;
}