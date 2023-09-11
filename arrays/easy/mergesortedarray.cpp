#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m;
        for(int j=0;j<nums2.size();j++){
            nums1.pop_back();
            nums1.insert(nums1.begin()+i,nums2[j]);
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};