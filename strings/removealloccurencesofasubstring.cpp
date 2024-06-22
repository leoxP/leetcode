#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Continue looping until 'part' is not found in 's'
        while(s.find(part)!= string::npos){
            int x=s.find(part);
            s.erase(x,part.size());
        }
        return s;
    }
};