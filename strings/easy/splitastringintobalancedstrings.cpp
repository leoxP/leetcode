#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int count1=0;
        int count2=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R'){
                count1++;
            }
            else if(s[i]=='L'){
                count2++;
            }
            if(count1==count2){
                count++;
            }
        }
        return count;
    }
};