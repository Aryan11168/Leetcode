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
    void help(TreeNode* root,vector<int>& pre){
        if(!root) return;
        pre.push_back(root->val);
        help(root->left,pre);
        help(root->right,pre);
        return;
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<int> pre;
        help(root,pre);
        root->left=nullptr;
        root->right=nullptr;
        TreeNode* temp=root;
        for(int i=1;i<pre.size();i++){
            temp->right=new TreeNode(pre[i]);
            temp=temp->right;
        }
        return;
    }
};