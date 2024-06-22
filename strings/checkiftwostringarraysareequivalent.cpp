#include <iostream>
#include <string>
using namespace std;

//O(n) solution:
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i1=0,i2=0,c1=0,c2=0;
        while(true){
            char x=word1[i1][c1];
            char y=word2[i2][c2];

            if(x!=y) return false;

            c1++;
            c2++;

            if(c1==word1[i1].size()){
                c1=0;
                i1++;
            }

            if(c2==word2[i2].size()){
                c2=0;
                i2++;
            }

            if(i1==word1.size() && i2==word2.size())
                break;

            if(i1==word1.size() || i2==word2.size())
                return false;
        }

        return true;
    }
};

//O(n^2) solution:
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="";
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word1[i].size();j++){
                s1+=word1[i][j];
            }
        }
        string s2="";
        for(int i=0;i<word2.size();i++){
            for(int j=0;j<word2[i].size();j++){
                s2+=word2[i][j];
            }
        }

        if(s1==s2){
            return true;
        }
        return false;
    }
};