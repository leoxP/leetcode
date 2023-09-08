#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        int k=1;
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
        }
        for(int i=n;i<n*2;i++){
            v.insert(v.begin()+k,nums[i]);
            k+=2;
        }
        return v;
    }
};