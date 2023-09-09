#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int MAX=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-nums[i]>MAX){
                    MAX=nums[j]-nums[i];
                }
            }
        }
        int num=(MAX==0)?-1:MAX;
        return num;
    }
};

//O(n) solution:

class Solution1 {
public:
    int maximumDifference(vector<int>& nums) {
        int diff=nums[1]-nums[0]; //initializing the first difference
        int min_e=nums[0];
        for(int i=1;i<nums.size();i++){
            diff=max(diff,nums[i]-min_e);
            min_e=min(min_e,nums[i]); //updating minimum element along the way
        }
        return diff<=0 ? -1:diff;
    }
};