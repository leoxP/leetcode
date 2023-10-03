#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool check=(sentence[0]==sentence[sentence.size()-1]);
        if(!check)
            return false;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1])
                return false;
        }
        return true;
    }
};