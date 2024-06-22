#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> res;
        int count=0;
        for(int i=0;i<bank.size();i++){
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')
                    count++;
            }
            if(count>0)
                res.push_back(count);
            count=0;
        }
        int x=0;
        if(res.size()==0) return 0;
        for(int i=0;i<res.size()-1;i++){
            cout<<res[i]<<endl;
            x+=res[i]*res[i+1];
        }
        res.clear();
        return x;
    }
};