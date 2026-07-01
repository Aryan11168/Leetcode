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
    TreeNode* gen(int a,int b,int i,int j,vector<int>& preorder, vector<int>& postorder){
        int n=preorder.size();
        if(min(a,i)<0 || max(a,i)>=n || min(b,j)<0 || max(b,j)>=n) return nullptr;
        if(a>b || i>j) return nullptr;
        TreeNode* node=new TreeNode(preorder[a]);
        unordered_set<int> s1;
        unordered_set<int> s2;
        int t1=a+1;
        int t2=i;
        while(t1<n && t2<n){
            s1.insert(preorder[t1]);
            s2.insert(postorder[t2]);
            if(s1==s2) break;
            t1++;
            t2++;
        }
        if(s1.empty() || s1!=s2) return node;
        node->left=gen(a+1,t1,i,t2,preorder,postorder);
        node->right=gen(t1+1,b,t2+1,j-1,preorder,postorder);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        return gen(0,n-1,0,n-1,preorder,postorder);
    }
};