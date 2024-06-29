
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
    int sum=0;
    void calc(TreeNode* root,int curr,int &maxi,int &sum){
        if(!root) return;

        if(curr==maxi) sum+=root->val;
        else if(curr>maxi){
            sum=root->val;
            maxi=curr;
        }

        calc(root->left,curr+1,maxi,sum);
        calc(root->right,curr+1,maxi,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int maxLevel=0;
        calc(root,0,maxLevel,sum);
        return sum;
    }
};