#include<iostream>
#include<queue>
using namespace std;

//Topological Sorting method
class Solution {
public:
    vector<int> topsort(vector<vector<int>> &edges,int n){
        vector<vector<int>> adj(n+1);
        vector<int> deg(n+1),order; //indegree of each edge
        for(auto x:edges){
            adj[x[0]].push_back(x[1]); //push the edges it points to into adjacency matrix
            deg[x[1]]++;
        }
        queue<int> q;
        //push all integers with in-degree 0 in the queue
        for(int i=1;i<=n;i++){
            if(deg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            order.push_back(x); //push back x
            n--;
            for(auto v:adj[x]){ //check the edges its pointing to
                if(--deg[v]==0) q.push(v); //if their indegree becomes 0 push them
            }
        }

        if(n!=0) return {};
        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rows=topsort(rowConditions,k);
        vector<int> cols=topsort(colConditions,k);

        if(rows.empty() || cols.empty()) return {};

        vector<vector<int>> matrix(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(rows[i]==cols[j]){
                    matrix[i][j]=rows[i]; //rows[i] decides element
                    //j decides column location
                }
            }
        }
        return matrix;
    }   
};