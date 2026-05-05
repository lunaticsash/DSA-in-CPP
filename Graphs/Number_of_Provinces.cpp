#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void dfs(int node, vector<int> adjLs[], int vis[]){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }

    int numProvinces(vector<int> adjLs[], int V){
        int vis[V] = {0};
        int count = 0;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;


    }


};