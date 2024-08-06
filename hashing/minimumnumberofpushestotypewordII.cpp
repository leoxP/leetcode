#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        map<char,int> mp;
        for(auto i:word) mp[i]++;

        vector<pair<char,int>> res;
        for(auto it:mp){
            res.push_back({it.first,it.second});
        }
        sort(res.begin(),res.end(),[](pair<char,int> &a,pair<char,int> &b){
            return a.second>b.second;
        });
        int keys=8;
        int push=1;
        int total=0;
        for(auto i:res){
            if(keys==0){
                keys=8;
                push++;
            }
            int x=i.second;
            total=total+(x*push);
            keys--;
        }
        return total;
    }
};

//More efficient
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c:word) freq[c-'a']++;

        sort(freq.rbegin(),freq.rend());

        int pushes = 0;
        for (int i=0;i<26;i++) {
            if(freq[i]==0) break;
            pushes+=(i/8+1)*freq[i];
        }
        return pushes;
    }
};