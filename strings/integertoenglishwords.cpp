#include<iostream>
using namespace std;

class Solution{
public:
    string numberToWords(int num){
    if(num==0) return "Zero";

    vector<string> ones={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> tens={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    vector<string> thousands={"","Thousand","Million","Billion"};

    string res="";
    int idx=0; //group index

    while(num>0){
        if(num%1000!=0){
            string groupres="";
            int part=num%1000;

            if(part>=100){
                groupres=ones[part/100]+" Hundred ";
                part%=100;
            }

            if(part>=20){
                groupres+=tens[part/10]+" ";
                part%=10;
            }

            if(part>0){
                groupres+=ones[part]+" ";
            }
            groupres+=thousands[idx]+" ";
            res=groupres+res;
        }
        num/=1000;
        idx++;
    }

    while(res.back()==' '){
        res.pop_back(); // remove trailing space
    }

    return res;
    }
};