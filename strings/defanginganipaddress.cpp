#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string x="";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                x+="[.]";
            }
            else{
                x+=address[i];
            }
        }
        return x;
    }
};