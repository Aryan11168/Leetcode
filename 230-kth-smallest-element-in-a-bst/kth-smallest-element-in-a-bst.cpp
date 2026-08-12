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
/*class Solution {
public:
    void helper(TreeNode* root, int& k, int& ans){
        if(root==nullptr) return;
        helper(root->left, k, ans);
        if(k==0) return;
         k--;
        if(k==0){
          ans=root->val;
          return;
        }
        helper(root->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        helper(root,k, ans);
        return ans;
    }
};*/
class Solution {
public:
    int helper(TreeNode* root, int& k){
        if(root==nullptr) return 0;
        int left=helper(root->left, k);
        if(k==0) return left;
        k--;
        if(k==0) return root->val;
        return helper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
};   