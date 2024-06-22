#include <iostream>
#include<set>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        map<int,vector<int>> m;
        for(int i=0;i<digits.size();i++){
            if(digits[i]==0) continue;
            else{
                for(int j=0;j<digits.size();j++){
                    if(j!=i){
                        m[digits[i]].push_back(digits[j]);
                    }
                }
            }
        }
        set<int> s;

        for(auto it:m){
            int num=it.first*100;
            for(int i=0;i<it.second.size();i++){
                for(int j=i+1;j<digits.size()-1;j++){
                    if((num+it.second[i]*10+it.second[j])%2==0) 
                        s.insert(num+it.second[i]*10+it.second[j]);
                    if((num+it.second[j]*10+it.second[i])%2==0)
                        s.insert(num+it.second[j]*10+it.second[i]);

                }
            }
        }
        vector<int> v(s.begin(),s.end());
        return v;
    }
};

//O(n) solution:

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
       vector<int> count(10,0);
       for(auto i:digits) count[i]++; //frequency count of digits

        vector<int> res;

        for(int i=100;i<=998;i+=2){
            vector<int> temp(10,0); //frequency count of digits in each number
            int num=i;

            while(num>0){
                int digit=num%10;
                temp[digit]++;
                num/=10;
            }

            bool check=true;
            for(int i=0;i<10;i++){
                if(temp[i]>count[i]){ //checking if number can be made from digits given
                    check=false;
                    break;
                }
            }

            if(check) res.push_back(i);
        }

        return res;
    }
};