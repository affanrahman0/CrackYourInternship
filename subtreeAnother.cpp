#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool func(TreeNode* root, TreeNode* subRoot,bool flag)
    {
        if(root==NULL && subRoot==NULL) return true;
        if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL)) return false;
        if(root->val == subRoot->val && func(root->left,subRoot->left,false) && func(root->right,subRoot->right,false)) return true;
        else if(flag && (func(root->left,subRoot,flag) || func(root->right,subRoot,flag))) return true;
        else return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return func(root,subRoot,true);
    }
};