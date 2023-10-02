#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minPartitions(string s) {
        int x=0;
        for(auto i:s){
            x=max(i-'0',x);
        }
        return x;
    }
};