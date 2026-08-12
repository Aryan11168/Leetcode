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

// preorder = [1, 2, 4, 8, 9, 5, 10, 3, 6, 7]
// inorder  = [8, 4, 9, 2, 10, 5, /1\, 6, 3, 7]

class Solution {
public:
    TreeNode* help(int l1,int r1,int l2,int r2,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& mpp){
        if(l1==r1) return new TreeNode(preorder[l1]);
        if(l1>r1) return nullptr;
        TreeNode* root=new TreeNode(preorder[l1]);
        int ind=mpp[preorder[l1]];
        int cnt=ind-l2;
        root->left=help(l1+1,l1+cnt,l2,ind-1,preorder,inorder,mpp);
        root->right=help(l1+cnt+1,r1,ind+1,r2,preorder,inorder,mpp);
        return root;  
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mpp;
        int n=preorder.size();
        for(int i=0;i<n;i++) mpp[inorder[i]]=i;
        return help(0,n-1,0,n-1,preorder,inorder,mpp);
    }
};