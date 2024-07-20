#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> grid(rowSum.size(),vector<int>(colSum.size(),-1));
        for(int i=0;i<rowSum.size();i++){
            for(int j=0;j<colSum.size();j++){
                int x=min(rowSum[i],colSum[j]);
                grid[i][j]=x;
                rowSum[i]-=x;
                colSum[j]-=x;
            }
        }
        return grid;
    }
};