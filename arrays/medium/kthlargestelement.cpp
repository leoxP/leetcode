#include <iostream>
#include <vector>
#include <map>
using namespace std;

//O(n) solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for (auto it=m.rbegin();it!=m.rend();it++){ //reverse iterator
            k-=it->second;
            if(k<=0) return it->first;
        }

        return 0;
    }
};
