/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void tra(TreeNode* root,vector<int>& pre){
        if(!root) return;
        tra(root->left,pre);
        pre.push_back(root->val);
        tra(root->right,pre);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> pre;
        tra(root,pre);
        int l=0;
        int r=pre.size()-1;
        while(l<r){
            int sum=pre[l]+pre[r];
            if(sum==k) return true;
            else if(sum<k) l++;
            else r--;
        }
        return false;
    }
};