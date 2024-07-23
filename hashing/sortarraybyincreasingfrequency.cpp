#include<iostream>
#include<map>
using namespace std;

//TC=O(NlogN)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        map<int,vector<int>> freq;   
        auto it=mp.begin();
        while(it!=mp.end()){
            int num=it->first;
            int f=it->second;
            freq[f].push_back(num);
            it++;
        } 

        vector<int> res;
        auto it2=freq.begin();
        while(it2!=freq.end()){
            int f=it2->first;
            vector<int> x=it2->second;
            if(x.size()>1) sort(x.begin(),x.end(),greater<>());
            for(int i=0;i<x.size();i++){
                for(int j=0;j<f;j++) res.push_back(x[i]);
            }
            it2++;
        }

        return res;
    }
};

//Creating comparator
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;

        sort(nums.begin(),nums.end(),[&](int x,int y){
            if(mp[x]==mp[y]) return x>y;
            return mp[x]<mp[y];
        });
        return nums;
    }
};

//TC=O(N)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> mp(201, 0);
        for(auto i:nums){
            mp[i+100]++; //to handle negative values
        }

        vector<vector<int>> freq(nums.size()+1);
        for (int i=0;i<201;i++) {
            if (mp[i]>0) {
                freq[mp[i]].push_back(i-100);
            }
        }

        vector<int> res;
        for (int f=0;f<freq.size();f++) {
            int size=freq[f].size();
            for(int i=size-1;i>=0;i--) {
                res.insert(res.end(),f,freq[f][i]);
            }
        }
        return res;
    }
};