#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    bool isFascinating(int n) {
        int x=n*2;
        int y=n*3;
        string s=to_string(n)+to_string(x)+to_string(y);
        unordered_map<char,int> m;
        for(auto i:s){
            m[i]++;
            if(m[i]>1 || i=='0') return false;
        }
        return true;
    }
};