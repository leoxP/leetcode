
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
    void helper(TreeNode* root,vector<int> &ans){
        if(!root) return;
        ans.push_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        helper(root1,res);
        helper(root2,res);
        sort(res.begin(),res.end());
        return res;
    }
};

// More efficient TC=O(N+M)
// Takes advantage of BST property when merging lists
class Solution {
public:
    void helper(TreeNode* root,vector<int> &ans){
        if(!root) return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
    }
    vector<int> merge(vector<int> res1,vector<int> res2){
        vector<int> merged;
        int i=0,j=0;
        while(i<res1.size() && j<res2.size()){
            if(res1[i]<res2[j]) merged.push_back(res1[i++]);
            else merged.push_back(res2[j++]);
        }

        while(i<res1.size()){
            merged.push_back(res1[i++]);
        }
        while(j<res2.size()){
            merged.push_back(res2[j++]);
        }
        return merged;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1,res2;
        helper(root1,res1);
        helper(root2,res2);
        return merge(res1,res2);
    }
};