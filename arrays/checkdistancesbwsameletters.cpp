#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,pair<int,int>> m;
        int k=0;
        for(char i:s){
            if(m.find(i)==m.end()){
                m[i].first=k;
                k++;
                continue;
            }
        m[i].second=k;
        k++;
        }
        for(auto i:m){
            if(i.second.second-i.second.first-1!=distance[int(i.first)-97]){
                return false;
            }
        }
        return true;
    }
};