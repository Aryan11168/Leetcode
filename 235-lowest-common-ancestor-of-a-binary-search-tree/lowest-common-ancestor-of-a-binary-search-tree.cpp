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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    TreeNode* curr=root;
    while(curr){
        if(curr==p || curr==q) return curr;
        int a=curr->val;
        int b=p->val;
        int c=q->val;
        if((a>b && a<c) || (a>c && a<b)) return curr;
        else if(a>b) curr=curr->left;
        else curr=curr->right;
    }
    return nullptr;
}


};