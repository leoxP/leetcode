#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n!=original.size()) return {};
        vector<vector<int>> v(m);
        int k=0;

        for(int i=0;i<original.size();i+=(original.size()/m)){
            for(int j=i;j<i+n;j++){
                v[k].push_back(original[j]);
            }
            k++;
        }
        return v;
    }
};