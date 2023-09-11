#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        for(auto it:m){
            for(int i=0;i<it.second.size()-1;i++){
                if(it.second[i+1]-it.second[i]<=k)
                    return true;
            }
        }
        return false;
    }
};

//O(n) solution:
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                if(i-m[nums[i]]<=k) return true;
            }
            m[nums[i]]=i;
        }
        return false;
    }
};