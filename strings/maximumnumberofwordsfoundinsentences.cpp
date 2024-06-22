#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count=0;
        int count1=0;
        for(int i=0;i<sentences.size();i++){
            for(int j=0;j<sentences[i].size();j++){
                if(sentences[i][j]==' '){
                    count++;
                }
                if(count>count1)
                    count1=count;
            }
            count=0;
        }
        return count1+1;
    }
};