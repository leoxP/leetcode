#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        int l=words[0].size();
        vector<vector<int>> v(words.size());
        int k=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<l-1;j++){
                v[k].push_back(int(words[i][j+1])-int(words[i][j]));
            }
            k++;
        }

        for(int i=1;i<words.size()-1;i++){
            if(v[i]!=v[i-1] && v[i]!=v[i+1]){
                return words[i];
            }
            if(v[i-1]!=v[i] && v[i-1]!=v[i+1]){
                return words[i-1];
            }
            if(v[i+1]!=v[i] && v[i+1]!=v[i-1]){
                return words[i+1];
            }
        }

        return "";
    }
};