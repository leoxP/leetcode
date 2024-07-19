#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> mini,maxi(matrix[0].size(),INT_MIN);
        for(int i=0;i<matrix.size();i++){
            int mine=INT_MAX; //min element per column
            for(int j=0;j<matrix[i].size();j++){
                mine=min(mine,matrix[i][j]);
                maxi[j]=max(maxi[j],matrix[i][j]); //max element per column
            }
            mini.push_back(mine);
        }
        vector<int> res;
        for(int i=0;i<mini.size();i++){
            for(int j=0;j<maxi.size();j++){
                if(mini[i]==maxi[j]) res.push_back(mini[i]);
            }
        }
        return res;
    }
};

//SC=O(1) comparing max of row mins & min of col maxes
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int rowminmax=INT_MIN;
        for(int i=0;i<n;i++){
            int rowmin=INT_MAX; //min element per column
            for(int j=0;j<m;j++){
                rowmin=min(rowmin,matrix[i][j]);
            }
            rowminmax=max(rowminmax,rowmin); //max value of row minimums
        }

        int colmaxmin=INT_MAX;
        for(int i=0;i<m;i++){
            int colmax=INT_MIN;
            for(int j=0;j<n;j++){
                colmax=max(colmax,matrix[j][i]);
            }
            colmaxmin=min(colmaxmin,colmax); //min of col maximums
        }
        //there can always only be one lucky number
        return (colmaxmin==rowminmax) ? vector<int>{rowminmax}:vector<int>{};
    }
};