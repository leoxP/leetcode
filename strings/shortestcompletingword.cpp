#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char,int> m;
        for(char i:licensePlate){
            if(isalpha(i))
                m[tolower(i)]++;
        }
        map<char,int> x=m;
        string res=" ";
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(x.find(words[i][j])!=x.end()){
                    x[words[i][j]]--;
                    if(x[words[i][j]]==0){
                        x.erase(words[i][j]);
                    }
                }
            }
            if(x.empty()){
                if(words[i].size()<res.size() || res==" ")
                    res=words[i];
            }
            x=m;
        }
        return res;
    }
};