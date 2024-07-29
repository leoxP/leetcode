#include<iostream>
using namespace std;

//Brute force
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int cnt=0;
        int n=rating.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if((rating[i]<rating[j] && rating[j]<rating[k]) || (rating[i]>rating[j] && rating[j]>rating[k])) cnt++;
                }
            }
        }
        return cnt;
    }
};

//Memoization TC=O(N^2)
class Solution {
public:
    int solve1(int idx,int size,vector<vector<int>> &dp,vector<int> &rating){
        if(size==3) return 1; //valid team found
        if(idx<0) return 0; //out of bound

        int validteams=0;

        if(dp[idx][size]!=-1) return dp[idx][size];

        for(int next=idx-1;next>=0;next--){
            if(rating[next]<rating[idx]){
                validteams+=solve1(next,size+1,dp,rating);
            }
        }
        return dp[idx][size]=validteams;
    }
    int solve2(int idx,int size,vector<vector<int>> &dp,vector<int> &rating){
        if(size==3) return 1;
        if(idx< 0) return 0;

        int validteams=0;

        if(dp[idx][size]!=-1) return dp[idx][size];

        for(int next=idx-1;next>=0;next--){
            if(rating[next]>rating[idx]){
                validteams+=solve2(next,size+1,dp,rating);
            }
        }
        return dp[idx][size]=validteams;
    }
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int teams=0;
        vector<vector<int>> increasing(n,vector<int>(4,-1));
        vector<vector<int>> decreasing(n,vector<int>(4,-1));

        for(int i=n-1;i>=0;i--){
            teams+=solve1(i,1,increasing,rating)+solve2(i,1,decreasing,rating);
        }
        return teams;
    }
};
