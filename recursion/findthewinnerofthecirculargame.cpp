#include<iostream>
#include<vector>
using namespace std;

int solver(vector<int> v,int s,int k){
    if(v.size()==1) return v[0];
    s=(s+k-1)%v.size();
    v.erase(v.begin()+s);
    return solver(v,s,k);
}

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        int s=0;
        return solver(v,s,k);
    }
};

//TC=O(n*k)
//SC=O(n)