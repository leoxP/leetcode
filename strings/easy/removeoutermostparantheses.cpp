#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int lp=0;
        int rp=0;
        int idx1=0;
        int idx2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                lp++;
            }
            else if(s[i]==')'){
                rp++;
                if(lp==rp)
                    idx2=i-1;
            }
            if(lp==rp){
                s.erase(idx1,1);
                s.erase(idx2,1);
                i-=2;
                idx1=i+2;
                lp=0;
                rp=0;
            }
        }
        return s;
    }
};

//Better solution:
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int opened=0;
        for(char i:s){
            if(i=='(' && opened++ > 0) res+=i;
            else if(i==')' && opened-- > 1) res+=i;
        }
        return res;
    }
};