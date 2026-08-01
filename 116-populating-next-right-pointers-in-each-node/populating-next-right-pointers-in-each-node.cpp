/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        vector<Node*> ans;
        ans.push_back(root);
        while(ans.size()>0){
            int n=ans.size();
            vector<Node*> temp;
            for(int i=0;i<n;i++){
                if(i+1<n){
                    ans[i]->next=ans[i+1];
                }
                else ans[i]->next=nullptr;
                if(ans[i]->left){
                    temp.push_back(ans[i]->left);
                }
                if(ans[i]->right){
                    temp.push_back(ans[i]->right);
                }
            }
            ans=temp;
        }
        return root;
    }
};