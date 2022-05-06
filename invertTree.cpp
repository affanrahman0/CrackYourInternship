#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(TreeNode* root)
    {
        if(root->left || root->right)
        {
            swap(root->left,root->right);
            if(root->left) dfs(root->left);
            if(root->right) dfs(root->right);
        }
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        dfs(root);
        return root;
    }
};