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
vector<int> rightSideView(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    queue<pair<TreeNode*,int>> q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty()){
        auto [node,hd] =q.front();q.pop();
        m[hd]=node->val;
        if(node->left){
            q.push({node->left,hd+1});
        }
        if(node->right){
            q.push({node->right,hd+1});
        }
    }
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
}
};