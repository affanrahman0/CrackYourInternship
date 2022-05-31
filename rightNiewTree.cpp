class Solution {
public:
    void func(vector<int> &ans,TreeNode* root,int level)
    {
        if(root==NULL) return;
        if(level== ans.size()) ans.push_back(root->val);
        if(root->right)
        {
            func(ans,root->right,level+1);
        }
        if(root->left)
        {
            func(ans,root->left,level+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
    
        vector<int> ans;
        if(root== NULL) return ans;
        func(ans,root,0);
//         queue<TreeNode* > q;
//         q.push(root);
//         while(!q.empty())
//         {
//             TreeNode *temp;
//             int n = q.size();
//             for(int i=0;i<n;i++)
//             {
//                 temp = q.front();
//                 q.pop();
//                 if(temp->left) q.push(temp->left);
//                 if(temp->right) q.push(temp->right);
                
//             }
//             ans.push_back(temp->val);
//         }
        return ans;
        
    }
};