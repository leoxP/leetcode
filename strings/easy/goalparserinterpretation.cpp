#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string x="";
        for(int i=0;i<command.size();i++){
            cout<<command[i]<<endl;
            if(command[i]=='G'){
                x+='G';
            }
            else if(command[i]=='(' && command[i+1]==')'){
                x+='o';
                i++;
            }
            else{
                x+="al";
                i+=3;
            }
        }
        return x;
    }
};