class Solution {
public:
    bool isBST(TreeNode* root ,long  min , long max){
           if (root==nullptr )return true;
            return (root->val > min && root->val <max&& isBST(root->left,min,root->val)&& isBST(root->right,root->val,max));
    }
    
    bool isValidBST(TreeNode* root) {
        return  isBST(root,LONG_MIN ,LONG_MAX );
        
    }
};