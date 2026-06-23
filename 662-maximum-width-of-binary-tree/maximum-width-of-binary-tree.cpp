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
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        int maxw=0;
        while(!q.empty()){
            int n=q.size();
            auto [w1,n1]=q.front();
            auto [w2,n2]=q.back();
            maxw=max(maxw,w2-w1+1);
            while(n--){
                auto [wide,node]=q.front();q.pop();
                wide=wide-w2;
                if(node->left) q.push({2*wide+1,node->left});
                if(node->right) q.push({2*wide+2,node->right});
            }
        }
        return maxw;
    }
};