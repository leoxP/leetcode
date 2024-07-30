#include<iostream>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        vector<int> count_a(n,0);
        int cnt=0;
        //count number of a's after each pos
        for(int i=n-1;i>=0;i--){
            count_a[i]=cnt;
            if(s[i]=='a') cnt++;
        }

        int min_deletions=n;
        cnt=0;
        //number of b's to the left
        for(int i=0;i<n;i++){
            min_deletions=min(count_a[i]+cnt,min_deletions);
            if(s[i]=='b') cnt++;
        }

        //at each index, you're checking for min number of letters to be deleted based on 
        //number of a's to the right and number of b's to the left
        //you want to minimize the number of a's to the right while doing the same for b's on the left
        
        return min_deletions;
    }
};