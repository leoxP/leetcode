#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int size=grid.size();
        for(int i=0;i<size;i++){
            if(grid[i][i]==0){
                return false;
            }
        }

        int j=0;
        for(int i=size-1;i>=0;i--){
            if(grid[j][i]==0){
                return false;
            }
            j++;
        }

        for(int i=0;i<size;i++){
            if(i==0 || i==size-1){
                for(int j=1;j<size-1;j++){
                    if(grid[i][j]!=0){
                        return false;
                    }
                }
            }
            else{
                for(int k=0;k<size;k++){
                    if(k!=i && k!=size-i-1){
                        if(grid[i][k]!=0){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};