#include <iostream>
#include <vector>
using namespace std;

// Using tabulation method
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1);

        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Using memoization
int solve(int n,vector<int> &dp){
    if(n<=2) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
}

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};