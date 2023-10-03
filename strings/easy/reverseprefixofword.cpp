#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(char i:word){
            if(i==ch){
                int p=word.find(i)+1;
                reverse(word.begin(),word.begin()+p);
                return word;
            }
        }
        return word;
    }
};