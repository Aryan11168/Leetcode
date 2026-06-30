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
    void help(TreeNode* root,vector<int>& trav){
        if(!root) return;
        help(root->left,trav);
        trav.push_back(root->val);
        help(root->right,trav);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> trav;
        help(root,trav);
        int n=trav.size();
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            ans=min(ans,abs(trav[i]-trav[i+1]));
        }
        return ans;
    }
};