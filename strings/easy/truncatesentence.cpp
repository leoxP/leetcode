#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int idx=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                k--;
            }
            if(k==0)
                break;
            idx++;
        }
        cout<<idx;
        return s.substr(0,idx-1);
    }
};