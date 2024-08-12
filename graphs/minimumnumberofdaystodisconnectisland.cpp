#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    bool isvalid(vector<vector<int>>& graph,int row,int col){
        return (row>=0 && row<graph.size() && col>=0 && col<graph[0].size() && graph[row][col]==1);
    }
    void floodfill(vector<vector<int>>& graph,int row,int col){
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        graph[row][col]=0;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            auto [currrow,currcol]=q.front();
            q.pop();
            for(auto dir:dirs){
                int newrow=currrow+dir[0];
                int newcol=currcol+dir[1];
                if(isvalid(graph,newrow,newcol)){
                    graph[newrow][newcol]=0;
                    q.push({newrow,newcol});
                }
            }
        }
    }
    int minDays(vector<vector<int>>& grid) {
        vector<vector<int>> graph=grid;
        int n=graph.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[0].size();j++){
                if(graph[i][j]==1){
                    cnt++;
                    floodfill(graph,i,j);
                }
            }
        }
        if(cnt!=1) return 0;

        for(int row=0;row<n;row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==0) continue; //skip water

                grid[row][col]=0;
                vector<vector<int>> temp=grid; //to check if removing cell, makes them disconnectec
                int newcount=0;

                for(int i=0;i<n;i++){
                    for(int j=0;j<temp[0].size();j++){
                        if(temp[i][j]==1){
                            newcount++;
                            floodfill(temp,i,j);
                        }
                    }
                }
                
                //if disconnected
                if(newcount!=1) return 1; //if 1 cell is enough to disconnect

                grid[row][col]=1;
            }
        }

        return 2; //max 2 cells needed to disconnect any orientation
    }
};