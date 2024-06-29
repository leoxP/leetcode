
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        auto it=max_element(nums.begin(),nums.end());
        int maxi=distance(nums.begin(), it);

        TreeNode* root=new TreeNode(nums[maxi]);

        vector<int> l(nums.begin(),nums.begin()+maxi);
        vector<int> r(nums.begin()+maxi+1,nums.end());

        root->left=constructMaximumBinaryTree(l);
        root->right=constructMaximumBinaryTree(r);
        return root;
    }
};

//More optimized solution:
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        auto it = max_element(nums.begin() + left, nums.begin() + right + 1);
        int maxi = distance(nums.begin(), it);

        TreeNode* root = new TreeNode(nums[maxi]);

        root->left = constructMaximumBinaryTree(nums, left, maxi - 1);
        root->right = constructMaximumBinaryTree(nums, maxi + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};
