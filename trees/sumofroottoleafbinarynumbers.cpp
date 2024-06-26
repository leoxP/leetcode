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
    int ans=0;
    void helper(TreeNode* root,string x){
        if(!root) return;
        x.push_back('0'+(root->val));
        if(!root->left && !root->right){
            helper2(x);
            return;
        }
        helper(root->left,x);
        helper(root->right,x);
    }
    void helper2(string x){
        ans=ans+stoi(x,nullptr,2);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        string x="";
        helper(root,x);
        return ans;
    }
};