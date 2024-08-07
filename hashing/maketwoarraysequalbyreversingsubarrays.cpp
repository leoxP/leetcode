#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto i:target) mp[i]++;
        for(auto i:arr){
            if(mp.find(i)==mp.end()) return false;
            mp[i]--;
            if(mp[i]==0) mp.erase(i);
        }
        return true;
    }
};