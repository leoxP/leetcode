#include<iostream>
using namespace std;

class Solution {
public:
    bool ismagic(vector<vector<int>> &grid,int row,int col){
        bool seen[10]={false};
        vector<int> rowsum(3,0);
        vector<int> colsum(3,0);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num=grid[row+i][col+j];
                if(num<1 || num>9) return false;
                rowsum[i]+=num;
                colsum[j]+=num;
                if(seen[num]) return false;
                seen[num]=true;
            }
        }

        int dg1=grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
        int dg2=grid[row+2][col]+grid[row+1][col+1]+grid[row][col+2];

        if(dg1!=dg2) return false;

        if(!(rowsum[0]==dg1 && rowsum[1]==dg1 && rowsum[2]==dg1)) return false;
        if(!(colsum[0]==dg1 && colsum[1]==dg1 && colsum[2]==dg1)) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int row=0;row+2<rows;row++){
            for(int col=0;col+2<cols;col++){
                if(ismagic(grid,row,col)) cnt++;
            }
        }
        return cnt;
    }
};