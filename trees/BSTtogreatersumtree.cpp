#include<iostream>
#include<vector>
#include<set>
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
    void helper(TreeNode* root,int &add){
        if(!root) return;
        helper(root->right,add);
        add+=root->val;
        root->val=add;
        helper(root->left,add);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int x=0;
        helper(root,x);
        return root;
    }
};