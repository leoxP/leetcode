#include<iostream>
#include<queue>
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> nodes(to_delete.begin(),to_delete.end());
        queue<TreeNode*> q;
        vector<TreeNode*> res;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left); //push to queue
                if(nodes.find(curr->left->val)!=nodes.end()){
                    curr->left=nullptr; //if to be deleted set to nullptr i.e. disjoin them
                }
            }
            if(curr->right){
                q.push(curr->right);
                if(nodes.find(curr->right->val)!=nodes.end()){
                    curr->right=nullptr;
                }
            }
            if(nodes.find(curr->val)!=nodes.end()){
                if(curr->left){
                    res.push_back(curr->left); //add nodes with no parent anymore
                }
                if(curr->right){
                    res.push_back(curr->right);
                }
            }
        }
        if(nodes.find(root->val)==nodes.end()){
            res.push_back(root);
        }
        return res;
    }
};