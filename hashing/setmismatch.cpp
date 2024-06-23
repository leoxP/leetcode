#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        vector<int> res(2);

        for(int i=1;i<nums.size()+1;i++){
            if(m[i]==0) res[1]=i;
            if(m[i]==2) res[0]=i;
        }
        return res;
    }
};