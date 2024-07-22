#include<iostream>
#include<map>
using namespace std;

//Using maps
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        int n=names.size();
        for(int i=0;i<n;i++){
            mp[heights[i]]=names[i];
        }
        auto it=mp.begin();
        for(int i=0;i<n;i++){
            names[n-i-1]=it->second;
            it++;
        }
        return names;
    }
};

