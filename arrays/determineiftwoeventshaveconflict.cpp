#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string e1s=event1[0];
        string e1e=event1[1];
        string e2s=event2[0];
        string e2e=event2[1];
        
        if(e2s<=e1e && e2e>=e1s) return true;

        return false;
    }
};