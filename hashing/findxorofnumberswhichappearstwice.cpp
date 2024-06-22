#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int xr=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                xr^=nums[i];
                continue;
            }
            m[nums[i]]++;
        }
        return xr;
    }
};

//Another solution with same TC=O(N)
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        ios_base::sync_with_stdio(0);

        int res = 0; 
        map<int,int> mp; 

        for (int num : nums)
            mp[num]++;

        for (auto num : mp)
            if (num.second == 2)
                res ^= num.first; 

        return res; 
    }
};