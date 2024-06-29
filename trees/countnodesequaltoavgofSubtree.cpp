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
    pair<int,int> helper(TreeNode* root,int &cnt){
        if(!root) return {0,0};
        auto l=helper(root->left,cnt);
        auto r=helper(root->right,cnt);

        int n=l.second+r.second+1;
        int sum=l.first+r.first+root->val;

        if(sum/n==root->val) cnt++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int x=0;
        auto it=helper(root,x);
        return x;
    }
};