#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==letter)
                count++;
        }
        count=count*100/s.size();
        return count;
    }
};