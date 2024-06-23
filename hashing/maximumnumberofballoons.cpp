#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(auto i:text){
            m[i]++;
        }
        string s="balloon";
        int maxi=INT_MAX;
        int cnt=6;
        for(auto i:s){
            if(i!='l' && i!='o') maxi=min(maxi,m[i]);
            else maxi=min(maxi,m[i]/2);
        }
        return max(maxi,0);
    }
};