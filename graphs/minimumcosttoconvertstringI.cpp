#include<iostream>
using namespace std;

//Floyd Warshal Algo (Most efficient)
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int inf=INT_MAX/10;
        vector<vector<int>> dist(26,vector<int>(26,inf));
        for(int i=0;i<original.size();i++){
            int x=original[i]-'a';
            int y=changed[i]-'a';
            dist[x][y]=min(dist[x][y],cost[i]);
        }

        //Floyd Warshal
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        long long res=0;
        int n=source.length();
        for(int i=0;i<n;i++){
            int src=source[i]-'a';
            int tgt=target[i]-'a';
            if(src!=tgt){
                if(dist[src][tgt]==inf){
                    return -1;
                }
                res+=dist[src][tgt];
            }
        }
        return res;
    }
};