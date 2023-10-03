#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> x;
        for(char i:s){
            if(x.find(i)==x.end())
                x.insert(i);
            else
                return i;
        }
        return -1;
    }
};