#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        m[0]=-1;
        for(auto it:arr){
            m[it]++;
        }
        for(auto i:arr){
            if(m[i*2]) return true;
        }
        return false;
    }
};