#include<iostream>
using namespace std;

//Quick Sort TLE
class Solution {
public:
    void quicksort(vector<int> &nums,int left,int right){
        if(left>=right) return;

        int pivot=nums[right];
        int partitionidx=partition(nums,left,right,pivot);

        quicksort(nums,left,partitionidx-1);
        quicksort(nums,partitionidx+1,right);
    }
    int partition(vector<int> &nums,int left,int right,int pivot){
        int partitionidx=left;
        for(int i=left;i<right;i++){
            if(nums[i]<pivot){
                swap(nums[i],nums[partitionidx]);
                partitionidx++;
            }
        }
        swap(nums[partitionidx],nums[right]);
        return partitionidx;
    }
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};

//Counting Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> count(2*50000+1,0); //range between -50k to 50k
        for(int num:nums){
            count[num+50000]++; //to map negative values
        }
        int idx=0; //store elements in nums itself
        for(int number_idx=0;number_idx<count.size();number_idx++){
            int freq=count[number_idx]; //freq of the number
            while(freq!=0){
                nums[idx]=number_idx-50000; //change nums accordingly
                idx++;
                freq--;
            }
        }
        return nums;
    }
};
