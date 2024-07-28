#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int inf=INT_MAX/10;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1); //numbered from 1 to n
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        //pair,container,how its stored(function)
        //min heap used (smallest element at top)
        //priority queue to process nodes in increasing order of their current travel time
        q.push({0,1}); //(time,node)

        vector<int> freq(n+1,0); //number of unique visits
        vector<int> dist(n+1,-1); //to store min time to reach node

        while(!q.empty()){
            auto [t,node]=q.top();
            q.pop(); //gets node with smallest time

            if(dist[node]==t || freq[node]>=2) continue;

            freq[node]++;
            dist[node]=t;

            if(node==n && freq[node]==2){
                return dist[node];
            }

            if((t/change)%2!=0){
                t=(t/change+1)*change;
            }

            for(int i:adj[node]){
                q.push({t+time,i}); //time is the time to travel
            }
        }
        return -1;
    }
};