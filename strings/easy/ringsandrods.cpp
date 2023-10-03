#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        map<int,set<char>> m;
        for(int i=1;i<rings.size();i+=2){
            m[rings[i]-'0'].insert(rings[i-1]);
        }
        int count=0;
        for(auto it:m){
            if(it.second.size()==3)
                count++;
        }
        return count;
    }
};