#include<iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);

        int pick=root->val+left.second+right.second; //second skips value
        int skip=max(left.first,left.second)+max(right.first,right.second); 
        //if skipping we choose the later best pick or skip so we take max
        
        return {pick,skip}; //first picks value, second skips value of current node youre at
    }
    int rob(TreeNode* root) {
        pair<int,int> p;
        p=solve(root);
        return max(p.first,p.second);
    }
};

//Without memoization TLE
class Solution {
public:
    int solve(TreeNode* root){
        if(!root) return 0;

        int currSkip=solve(root->left)+solve(root->right); 
        int currRob=root->val; 

        if(root->left) currRob+=solve(root->left->left)+solve(root->left->right);
        if(root->right) currRob+=solve(root->right->left)+solve(root->right->right);

        return max(currSkip,currRob);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};

//With memoization
class Solution {
public:
    int solve(TreeNode* root,unordered_map<TreeNode*,int> &m){
        if(!root) return 0; //base case 
        if(m.count(root)) return m[root]; //if it exists basically

        //2 possibilities at each node
        int currSkip=solve(root->left,m)+solve(root->right,m); 
        int currRob=root->val; 

        //if you rob at node, then cannot rob left child but you can rob the left childs children
        if(root->left) currRob+=solve(root->left->left,m)+solve(root->left->right,m);
        if(root->right) currRob+=solve(root->right->left,m)+solve(root->right->right,m);

        return m[root]=max(currSkip,currRob);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> m;
        return solve(root,m);
    }
};