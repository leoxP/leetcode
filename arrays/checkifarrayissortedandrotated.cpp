#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                cnt++; //checks number of times ascending order is broken
            }
        } 
        if(nums[nums.size()-1]>nums[0]) cnt++; //if rotated the last element should be smaller than 1st
        if(cnt<=1) return true;
        else return false;
    }
};

class Solution1{
public:
    bool check(vector<int>& nums) {
        int largepos=0;
        int largest=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest){
                largest=nums[i];
            }
        }
        
        int small=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                largepos=i;
                break;
            }
            if(i+1==nums.size()-1){
                return true;
            }
        }

        for(int i=largepos+1;i<nums.size();i++){
            if(nums[i]>small || (nums[i]<nums[i-1] && i!=largepos+1)){
                return false;
            }
        }

        return true;
    }
};