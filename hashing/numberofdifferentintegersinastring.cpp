#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<set>
using namespace std;

//TC=O(NlogM)
class Solution {
public:
    string removeLeadingZeros(string num) {
        int start = 0;
        while (start<num.size()-1 && num[start]=='0') {
            start++;
        }
        return num.substr(start);
    }
    int numDifferentIntegers(string word) {
        string s;
        for(auto i:word){
            if(isdigit(i)) s.push_back(i);
            else s.push_back(' ');
        }
        set<string> st;
        string x;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                x.push_back(s[i]);
            }
            if(s[i]==' ' && x.size()>0){
                st.insert(removeLeadingZeros(x));
                x="";
            }
        }
        if(x.size()>0) st.insert(removeLeadingZeros(x));
        return st.size();
    }
};

//TC=O(N)
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        for (int i = 0; i < word.size(); i++) {
            string number = "";
            if (isdigit(word[i])) {
                while (i < word.size() && isdigit(word[i])) {
                    number += word[i];
                    i++;
                }
                number.erase(0, min(number.find_first_not_of('0'), number.size()-1));
                st.insert(number);
            }
        }
        return st.size();
    }
};
