#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(x<=90 && x>=65){
                s[i]=x+32;
            }
        }
        return s;
    }
};