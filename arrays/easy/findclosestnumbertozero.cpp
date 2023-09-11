#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest=10e5;
        int index=-1;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<closest){
                closest=abs(nums[i]);
                index=i;
            }
            if(abs(nums[i])==abs(nums[index])){
                if(nums[i]>nums[index]){
                    index=i;
                }
            }
        }
        return nums[index];
    }
};