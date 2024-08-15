#include<iostream>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());

        vector<int> dists(maxi+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(nums[i]-nums[j]);
                dists[dist]++;
            }
        }
        for(int dist=0;dist<=maxi;dist++){
            k-=dists[dist];
            if(k<=0) return dist;
        }
        return -1;
    }
};