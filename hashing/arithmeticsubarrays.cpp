#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

//TC=O(N*MlogM)
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for(int i=0;i<l.size();i++){
            vector<int> sub(nums.begin()+l[i],nums.begin()+r[i]+1);
            if(sub.size()<2){
                res.push_back(true);
                continue;
            }
            sort(sub.begin(),sub.end());
            bool x=true;
            int diff=sub[1]-sub[0];
            for(int j=1;j<sub.size();j++){
                if(sub[j]-sub[j-1]!=diff) x=false;
            }
            res.push_back(x);
        }
        return res;
    }
};

//TC=O(N)
