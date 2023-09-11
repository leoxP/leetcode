#include<iostream>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> v;
        int sum=0;
        int start=0;
        for(int i=0;i<nums.size();i++){
            sum=(2*start)+nums[i];
            if(sum%5==0) v.push_back(true);
            else v.push_back(false);
            if(sum>=5) sum-=5;
            start=sum;
        }
        return v;

        //Logic: sum=(2*prevsum)+digit 
        //if sum>=5 subtract
        //if sum divisible by 5, number is as well
    }
};