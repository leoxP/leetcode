#include<iostream>
using namespace std;

//Memoization
class Solution {
public:
    int solve(int idx,int remainingwidth,int height,vector<vector<int>> &books,int &width,vector<vector<int>> &dp){
        if(idx<0) return height; //all books placed
        vector<int> curr=books[idx];

        if(dp[idx][remainingwidth]!=-1) return dp[idx][remainingwidth];
        
        int currwidth=curr[0];
        int currheight=curr[1];

        int skip=height+solve(idx-1,width-currwidth,currheight,books,width,dp); //next shelf
        
        int pick=INT_MAX;
        if(remainingwidth>=currwidth){
            pick=solve(idx-1,remainingwidth-currwidth,max(height,currheight),books,width,dp); //same shelf
        }
        return dp[idx][remainingwidth]=min(skip,pick);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>> dp(n,vector<int>(shelfWidth+1,-1));
        return solve(n-1,shelfWidth,0,books,shelfWidth,dp);
    }
};