#include <iostream>
#include <vector>
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
    bool findpath(TreeNode* root, int x,string &s){
        if(!root) return false;
        if(root->val==x) return true;

        s.push_back('L');
        if(findpath(root->left,x,s)) return true;
        s.pop_back();

        s.push_back('R');
        if(findpath(root->right,x,s)) return true;
        s.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string l="";
        string r="";
        findpath(root,startValue,l);
        findpath(root,destValue,r);

        int i = 0;
        while (i < l.size() && i < r.size() && l[i] == r[i]) {
            i++; //find common prefix length
        }
        //remove common part from both (if both on same side)
        //we need to remove common path from them to LCA
        string up(l.size()-i,'U'); 
        string down=r.substr(i);
        return up+down;
    }
};