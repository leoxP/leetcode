#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        map<int,int> m;
        for(auto i:nums)
            m[i]++;
        for(auto it:m){
            if(it.second==n) return it.first;
        }
        return -1;
    }
};