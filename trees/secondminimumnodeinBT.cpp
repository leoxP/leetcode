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
    set<int> s;
    void helper(TreeNode* root){
        if(!root) return;
        s.insert(root->val);
        helper(root->left);
        helper(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        helper(root);
        set<int>::iterator i=s.begin();
        i++;
        if(s.size()<=1) return -1;
        return *i;
    }
};

//Morris Traversal O(1) SC
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;

        long long first_min=root->val;
        long long second_min=LONG_MAX;
        while(root){
            if(!root->left){
                if(root->val>first_min && root->val<second_min){
                    second_min=root->val;
                }
                root=root->right;
            }
            else{
                TreeNode* pre=root->left;
                while(pre->right && pre->right!=root){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=root;
                    root=root->left;
                }
                else{
                    pre->right=nullptr;
                    if(root->val>first_min && root->val<second_min){
                        second_min=root->val;
                    }
                    root=root->right;
                }
            }
        }
        return second_min==LONG_MAX? -1:second_min;
    }
};