#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();i++){
            if(bits[i]==1){
                i++;
                if(i>=bits.size()-1){
                    return false;
                }
            }
        }
        return true;
    }
};