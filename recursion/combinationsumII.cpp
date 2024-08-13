#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void solve(int idx,int target,vector<int> &ds,vector<int> &arr){
        if(target==0){
            res.push_back(ds);
            return;
        }

        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;

            if(arr[i]>target) break;

            ds.push_back(arr[i]);
            solve(i+1,target-arr[i],ds,arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        solve(0,target,ds,candidates);

        return res;
    }
};