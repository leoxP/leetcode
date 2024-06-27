#include<iostream>
#include<vector>
#include<queue>
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
    bool helper(TreeNode* root,int &sum, int targetSum){
        if(!root) return false;
        if(!root->left && !root->right){
            sum+=root->val;
            cout<<sum<<endl;
            if(sum==targetSum) return true;
            else{
                //sum-=root->val;
                return false;
            }
        }

        sum+=root->val;
        cout<<sum<<endl;
        bool l=helper(root->left,sum,targetSum);
        if(!l){
            if(root->left) sum-=root->left->val;
        }
        bool r=helper(root->right,sum,targetSum);
        if(!r){
            if(root->right) sum-=root->right->val;
        }
        return (l || r);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=helper(root,sum,targetSum);
        return ans;
    }
};

// More efficient code:
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        if(!root->left && !root->right){
            return root->val==targetSum;
        } 

        bool l=hasPathSum(root->left,targetSum-root->val);
        bool r=hasPathSum(root->right,targetSum-root->val);

        return (l||r);
    }
};