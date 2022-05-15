#include<bits/stdc++.h>
using namespace std;
void recur(TreeNode* root,queue<int>& que)
{
    if(root->left) recur(root->left,que);
    que.push(root->val);
    if(root->right) recur(root->right,que);
}
class BSTIterator {
public:
    queue<int> que;
    BSTIterator(TreeNode* root) {
       
        recur(root,que);
        
    }
    
    int next() {
        
       int temp = que.front();
        que.pop();
        return temp;
           
    }
    
    bool hasNext() {
         if(!que.empty()) return true;
        else return false;
    }
};