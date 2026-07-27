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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=slow->next;
        slow->next=nullptr;
        ListNode* prev=nullptr;
        while(newHead){
            ListNode* node=newHead->next;
            newHead->next=prev;
            prev=newHead;
            newHead=node;
        }
        newHead=prev;
        ListNode* temp=head;
        while(temp && newHead){
            ListNode* node=temp->next;
            ListNode* nextnode=newHead->next;
            temp->next=newHead;
            newHead->next=node;
            temp=node;
            newHead=nextnode;
        }
        return ;
    }
};