#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int maxrow=matrix.size();
        int maxcol=matrix[0].size();
        vector<int> res;
        int dir=0;

        int top=0,bottom=maxrow-1,left=0,right=maxcol-1;
        int i=0,j=0;

        //right,down,left,up
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        while(res.size()<(maxrow*maxcol)){
            res.push_back(matrix[i][j]);

            int nexti=i+dirs[dir][0];
            int nextj=j+dirs[dir][1];
            if(nexti<top || nexti>bottom || nextj<left || nextj>right){
                if(dir==0) top++;
                if(dir==1) right--;
                if(dir==2) bottom--;
                if(dir==3) left++;

                dir=(dir+1)%4;
                nexti=i+dirs[dir][0]; 
                nextj=j+dirs[dir][1]; //when boundary occurs the value gets updated
            }
            i=nexti;
            j=nextj;
        }
        return res;
    }
};