#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }

        for(auto it:m){
            if(it.second>arr.size()/4) return it.first;
        }

        return -1;
    }
};