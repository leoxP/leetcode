#include<iostream>
#include<queue>
using namespace std;

//Flood Fill Algo
class Solution {
public:
    bool isvalidcell(vector<vector<char>> &grid,int row,int col){
        return (row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]=='1');
    }
    void floodfill(vector<vector<char>> &grid,int row,int col){
        //right,down,up,left
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        grid[row][col]='0';

        q.push({row,col});
        while(!q.empty()){
            auto [currrow,currcol]=q.front();
            q.pop();
            for(auto dir:dirs){
                int newrow=currrow+dir[0];
                int newcol=currcol+dir[1];
                if(isvalidcell(grid,newrow,newcol)){
                    grid[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    floodfill(grid,i,j);
                }
            }
        }
        return cnt;
    }
};