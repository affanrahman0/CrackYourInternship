class Solution
{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        int big=(p->val>q->val)?p->val:q->val;
        int small=(p->val<q->val)?p->val:q->val;
        if(big<root->val)
            return lowestCommonAncestor(root->left,p,q);
        if(small>root->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};
