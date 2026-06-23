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

int indx(vector<int>& vec,int l,int r,int tar){
    for(int i=l;i<=r;i++){
        if(vec[i]==tar) return i;
    }
    return -1;
}

TreeNode* build(vector<int>& inorder, vector<int>& postorder,int l1,int r1,int l2,int r2){
    if(l1>r1 || l2>r2) return nullptr;
    if(l1==r1) return new TreeNode(inorder[l1]);
    TreeNode* node=new TreeNode(postorder[r2]);
    int m=indx(inorder,l1,r1,postorder[r2]);
    int cntl=m-l1;
    int cntr=r1-m;
    node->left=build(inorder,postorder,l1,m-1,l2,l2+cntl-1);
    node->right=build(inorder,postorder,m+1,r1,l2+cntl,r2-1);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    int n=inorder.size();
    return build(inorder,postorder,0,n-1,0,n-1);
}


};