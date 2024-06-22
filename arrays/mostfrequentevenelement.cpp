#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        int max_f=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) m[nums[i]]++;
            if(m[nums[i]]>max_f) max_f=m[nums[i]];
        }
        int min_e=10e5;

        for(auto it:m){
            if(it.second>=max_f){
                min_e=min(min_e,it.first);
            }
        }
        return max_f==0 ? -1 : min_e;
    }
};