#include<iostream>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills){
        int five=0;
        int ten=0;
        for(int i=0;i<bills.size();i++){
            int x=bills[i];
            if(x==5) five++;
            else{
                if(x==10){
                    five-=1;
                    ten++;
                    if(five<0) return false;
                }
                if(x==20){
                    if(five>=1 && ten>=1){
                        five-=1;
                        ten-=1;
                    }
                    else if(five>=3){
                        five-=3;
                    }
                    else{
                        return false;
                    }
                    if(five<0 || ten<0) return false;
                }
            }
        }
        return true;
    }
};