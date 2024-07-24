#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int x=0;
            int y=0;
            int i=0;
            if(a==0) x=mapping[0];
            else{
                while(a>0){
                    int r=a%10;
                    x+=mapping[r]*pow(10,i);
                    i++;
                    a/=10;
                }
            }
            i=0;
            if(b==0) y=mapping[0];
            else{
                while(b>0){
                    int r=b%10;
                    y+=mapping[r]*pow(10,i);
                    i++;
                    b/=10;
                }
            }   
            return x<y;
        });
        return nums;
    }
};

//TC=O(NlogN)
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> pairs; //mapping, index of number
        for(int i=0;i<nums.size();i++){
            int mappedval=0;
            int num=nums[i];
            if(num==0){
                pairs.push_back({mapping[0],i});
                continue;
            }
            int j=0;
            while(num!=0){
                int r=num%10;
                mappedval+=mapping[r]*pow(10,j);
                j++;
                num/=10;
            }
            pairs.push_back({mappedval,i});
        }
        sort(pairs.begin(),pairs.end());
        vector<int> res;
        for(auto it:pairs){
            res.push_back(nums[it.second]);
        }
        return res;
    }
};