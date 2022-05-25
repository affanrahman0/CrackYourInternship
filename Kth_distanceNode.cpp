#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void fparent(unordered_map<TreeNode*,TreeNode*>& parent,TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty())
        {
            TreeNode* temp =  q.front();
            q.pop();
            if(temp->left) {
                q.push(temp->left);
                parent[temp->left] = temp;
            }
            if(temp->right) 
            {
                q.push(temp->right);
                parent[temp->right] = temp;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        fparent(parent,root);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target] = true;
        int level = 0;
        while(!q.empty())
        {
            if(level++ ==k) break;
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                TreeNode* temp = q.front();
                
                q.pop();
                
                if(temp->left && !vis[temp->left] )
                {
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                if(temp->right && !vis[temp->right] )
                {
                    q.push(temp->right);
                    vis[temp->right] = true;
                }
                if(parent[temp] && !vis[parent[temp]] )
                {
                    q.push(parent[temp]);
                    vis[parent[temp]] = true;
                }
            }
            
        }
        vector<int> ans;
            while(!q.empty())
            {
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);
            }
            return ans;
    }
};