#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> que;
        que.push(root);
        int sum = 0;
        while(!que.empty())
        {
            int n = que.size();
            while(n--)
            {
                
                TreeNode* temp = que.front();
                que.pop();
                cout<<temp->val<<endl;
                if(temp->val>=low && temp->val<=high) sum+= temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
                
            }
            
        }
        return sum;
    }
};