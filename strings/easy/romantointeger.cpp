#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        map<char,int> m;

        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        for(int i=0;i<s.size();i++){
            if(m[s[i]]!=m[s[i+1]] && m[s[i]]<m[s[i+1]]){
                sum-=m[s[i]];
                continue;
            }
            sum+=m[s[i]];
        }
        return sum;
    }
};