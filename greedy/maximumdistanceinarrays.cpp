#include<iostream>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int diff=INT_MIN;
        int maxi=arrays[0].back(); //global max
        int mini=arrays[0][0]; //global min
        for(int i=1;i<arrays.size();i++){
            int currmax=arrays[i].back();
            int currmin=arrays[i][0];
            diff=max(diff,max(abs(currmax-mini),abs(maxi-currmin)));

            maxi=max(maxi,currmax);
            mini=min(mini,currmin);
        }
        return diff;
    }
};