#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        string s1=s.substr(0,s.size()/2);
        string s2=s.substr(s.size()/2,s.size());
        int c1=0,c2=0;
        set<char> x={'a','e','i','o','u'};
        for(char i:s1){
            if(x.find(tolower(i))!=x.end()){
                c1++;
            }
        }
        for(char i:s2){
            if(x.find(tolower(i))!=x.end()){
                c2++;
            }
        }
        if(c1==c2)
            return true;
        return false;
    }
};