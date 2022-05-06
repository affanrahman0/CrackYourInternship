#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int height(TreeNode* root,int& maxi)
    {
        if(root==nullptr) return 0;
        
        int l = height(root->left,maxi);
        int r = height(root->right,maxi);
        
        maxi = max(maxi,l+r);
        
        return 1+((l>r)?l:r);
    }
    // void recur(int& d,TreeNode* root)
    // {
    //     if(root==nullptr) return;
    //     if(root->left) recur(d,root->left);
    //     if(root->right) recur(d,root->right);
    //     int a = height(root->left)+height(root->right);
    //     if(a>d) d=a;
    // }
    int diameterOfBinaryTree(TreeNode* root) {
        int d =0;
        height(root,d);
        // int p = height(root);
        return d;
        //return height(root->left)+height(root->right);
    }
};