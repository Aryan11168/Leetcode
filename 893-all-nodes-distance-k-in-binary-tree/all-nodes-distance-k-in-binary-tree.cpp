/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void distbelow(TreeNode* root,int k,vector<int>& temp){
        if(k<0) return;
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && k--){
            int n=q.size();
            while(n--){
                TreeNode* node=q.front();q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        while(!q.empty()){
            TreeNode* node=q.front();q.pop();
            temp.push_back(node->val);
        }
        return ;
    }
    int cnt;
    bool help(TreeNode* root,TreeNode* target,int k,vector<int>& temp){
        if(!root) return false;
        if(root==target){
            distbelow(root,k,temp);
            return true;
        }
        bool l=help(root->left,target,k,temp);
        bool r=help(root->right,target,k,temp);
        if(l){
            cnt++;
            if(k-cnt==0){
                temp.push_back(root->val);
            }
            else distbelow(root->right,k-cnt-1,temp);
        }
        else if(r){
            cnt++;
            if(k-cnt==0){
                temp.push_back(root->val);
            }
            else distbelow(root->left,k-cnt-1,temp);
        }
        return l|r;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> temp;
        cnt=0;
        help(root,target,k,temp);
        return temp;
    }
};