#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int func(TreeNode* root, int tar,long long pre)
    {
        if(!root) return 0;
        long long  current = pre + root->val;
        
        return (current == tar) + func(root->left,tar,current) + func(root->right,tar,current);
    }
    int pathSum(TreeNode* root, int target) {
        
        if(!root) return 0;
        
        return func(root,target,0) + pathSum(root->left,target) + pathSum(root->right,target);
    }
};