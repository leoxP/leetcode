#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        int l=0;
        int r=0;
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='i'){
                reverse(s.begin(),s.begin()+r);
                s.erase(i,1);
                i--;
                continue;
            }
            r++;
        }
        return s;
    }
};