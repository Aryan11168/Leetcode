/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        if(k==0) return head;
        ListNode* temp=head;
        int l=1;
        while(temp->next){
            temp=temp->next;
            l++;
        }
        k=k%l;
        if(k==0) return head;
        temp->next=head;
        temp=head;
        // l=0
        // l=5 ,k=1 , temp=head -> 
        int steps=l-k-1;
        while(steps--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};