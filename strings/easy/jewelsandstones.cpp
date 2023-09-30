#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution{
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        map<char,int> m;
        for(int i=0;i<jewels.size();i++){
            m[jewels[i]]++;
        }
        for(int j=0;j<stones.size();j++){
            if(m.find(stones[j])!=m.end()){
                count++;
            }
        }
        return count;
    }
};