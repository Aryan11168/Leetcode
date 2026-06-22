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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxl=0;
        while(!q.empty()){
            auto [n1,w1]=q.front();
            auto [n2,w2]=q.back();
            maxl=max(maxl,w2-w1+1);
            int n=q.size();
            while(n--){
                auto[node,wid]=q.front();q.pop();
                wid=wid-w2;
                if(node->left) q.push({node->left,2*wid +1});
                if(node->right) q.push({node->right,wid*2+2});
            }
        }
        return maxl;
    }
};