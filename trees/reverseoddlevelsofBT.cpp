
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

//TC=O(N) & SC=O(N) [BFS Approach]
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*> currlevel;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                currlevel.push_back(curr);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(lvl%2==1){
                int i=0;
                int j=currlevel.size()-1;
                while(i<j){
                    swap(currlevel[i]->val,currlevel[j]->val);
                    i++;j--;
                }
            }
            lvl++;
        }
        return root;
    }
};

//More efficient: TC=O(N) & SC=O(LogN) [DFS Approach]
class Solution {
public:
    void preorder(TreeNode* rootLeft,TreeNode* rootRight,int lvl){
        if(rootLeft && rootRight){
            if(lvl%2==1){
                swap(rootLeft->val,rootRight->val);
            }
            preorder(rootLeft->left,rootRight->right,lvl+1);
            preorder(rootLeft->right,rootRight->left,lvl+1);
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        preorder(root->left,root->right,1);
        return root;
    }
};