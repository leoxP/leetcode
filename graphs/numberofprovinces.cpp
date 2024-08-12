#include<iostream>
using namespace std;

//dfs
class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<bool> &vis,int i){
        vis[i]=true; //mark the node as visited
        for(int j=0;j<graph.size();j++){
            if(graph[i][j]==1 && !vis[j]){
                dfs(graph,vis,j); //next checks for visited in j node
            }
        }
    }
    int findCircleNum(vector<vector<int>> &graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(graph,vis,i);
            }
        }
        return cnt;
    }
};