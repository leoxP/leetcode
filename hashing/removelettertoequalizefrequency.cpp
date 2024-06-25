#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> m;
        for(auto i:word){
            m[i]++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            it->second--;
            unordered_set<int> freq;
            for(auto j:m){
                if(j.second>0) freq.insert(j.second);
            }
            if(freq.size()==1) return true;
            it->second++;
        }
        return false;
    }
};