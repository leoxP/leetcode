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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return root1;
        if(!root1 || !root2) return root1? root1:root2;
        queue<TreeNode*> q1,q2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()){
            TreeNode* curr1=q1.front();
            TreeNode* curr2=q2.front();
            q1.pop();
            q2.pop();

            curr1->val+=curr2->val;
            if(!curr1->left && curr2->left) curr1->left=curr2->left;
            else if(curr1->left && curr2->left){
                q1.push(curr1->left);
                q2.push(curr2->left);
            }
            if(!curr1->right && curr2->right) curr1->right=curr2->right;
            else if(curr1->right && curr2->right){ //if there's a curr1 right and no curr2 right, then no need to check cuz curr1 will keep it's right
                q1.push(curr1->right);
                q2.push(curr2->right);
            }
        }
        return root1;
    }
};

//Recursive Method
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        root1->val+=root2->val;
        //if there's no root2 left or right, the left or right remains same
        if(root2->left) root1->left=mergeTrees(root1->left,root2->left);
        if(root2->right) root1->right=mergeTrees(root1->right,root2->right);

        return root1;
    }
};