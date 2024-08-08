#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;

        int r=rStart,c=cStart;
        res.push_back({r,c});

        int moves=0,dir=0;
        //right,bottom,left,top (row,col)
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        while(res.size()<rows*cols){
            if(dir%2==0){ //0 and 2
                moves++;
            }

            for(int i=0;i<moves;i++){
                r+=dirs[dir][0];
                c+=dirs[dir][1];

                if(r>=0 && r<rows && c>=0 && c<cols) res.push_back({r,c});
            }

            dir=(dir+1)%4; //can be any 4 directions
        }

        return res;
    }
};