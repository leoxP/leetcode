#include<iostream>
using namespace std;

//Floyd Warshal technique
class Solution {
public:
    int inf=INT_MAX/4;
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dist(n,vector<int>(n,inf));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<int> cities;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(dist[i][j]<=d) cities.push_back(j);
                }
            }
            res.push_back(cities);
        }
        int mini=INT_MAX;
        int city=-1;
        for(int i=0;i<res.size();i++){
            if(res[i].size()<=mini){
                city=i;
                mini=res[i].size();
            }
        }
        return city;
    }
};

//Slightly more different code
class Solution {
public:
    int inf=INT_MAX/4;
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dist(n,vector<int>(n,inf));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int minReachable=n;
        int city=-1;
        for(int i=0;i<n;i++) {
            int reachable = 0;
            for(int j=0;j<n;j++) {
                if (i!=j && dist[i][j]<=d) {
                    reachable++;
                }
            }
            if(reachable<=minReachable) {
                minReachable=reachable;
                city=i;
            }
        }
        return city;
    }
};

