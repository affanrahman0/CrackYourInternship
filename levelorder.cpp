class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty())    
        {
           
            vector<int> cur;
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                 TreeNode* temp = q.front();
                 q.pop();
                 cur.push_back(temp->val);
                 if(temp->left!=nullptr) q.push(temp->left);
                 if(temp->right!=nullptr) q.push(temp->right);
            }
            res.push_back(cur);
            cur.clear();
            
         }
        
        return res;
        
    }
};