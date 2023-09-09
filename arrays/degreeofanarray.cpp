#include <iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> m;
        if(nums.size()==1) return 1;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int num=0;
        int freq=0;
        vector<int> v;
        for(auto it:m){
            if(it.second>=freq){
                    num=it.first;
                    freq=it.second;
            }
        }

        for(auto it:m){
            if(it.second==freq){
                v.push_back(it.first);
            }
        }

        int count=10e5;

        for(int i=0;i<v.size();i++){
            int check=v[i];
            int l=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==check) break;
                l++;
            }
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]==check) break;
                l++;
            }
            if(nums.size()-l<count){
                count=nums.size()-l;
            }
        }
        return count;
    }
};

//O(n) solution down below:
class Solution1{
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,pair<int,vector<int>>> m; 
        //ading the positions of the elements in a vector 
        //to track closest and furthest element to check for shortest subarray
        int freq=0;

        for(int i=0;i<nums.size();i++){
            m[nums[i]].first++;
            m[nums[i]].second.push_back(i);
            if(m[nums[i]].first>freq){
                freq=m[nums[i]].first;
            }
        }

        int smallest=nums.size();

        for(auto it:m){
            if(it.second.first==freq){
                smallest=min(smallest,it.second.second.back()-it.second.second[0]+1);
            }
        }

        return smallest;
    }
};