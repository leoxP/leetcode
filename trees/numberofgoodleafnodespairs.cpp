#include<iostream>
#include<vector>
#include<stack>
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
    int count=0;
    const int MAX_DISTANCE=10;

    vector<int> dfs(TreeNode* root,int d){
        if(!root) return vector<int>(MAX_DISTANCE+1,0);

        if(!root->left && !root->right){
            vector<int> res(MAX_DISTANCE+1,0);
            res[1]=1; //at distance of 1 from its parent 
            //res[dist]=no of leaf nodes
            return res;
        }

        vector<int> left=dfs(root->left,d);
        vector<int> right=dfs(root->right,d);

        for(int i=1;i<=d;i++){
            for(int j=1;j<=d-i;j++){ //i + j <= d
                count+=left[i]*right[j];
            }
        }
        //left[i] and right[j] represent the number of leaf nodes at distances i and j from the left and right children
        //so for counting pairs we multiply their values and add to count

        vector<int> res(MAX_DISTANCE+1,0); //we are updating for non leaf nodes
        for(int i=1;i<MAX_DISTANCE;i++){
            res[i+1]=left[i]+right[i]; 
            //res[dist+1]=sum of number of leaf nodes on each side 
            //since we are going up a level we add them
        }

        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return count;
    }
};