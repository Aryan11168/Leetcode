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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        // (-1) 
       ListNode* ans =new ListNode(-1);
       // ans (-1)
       ListNode* temp=ans;
       // l1 ()-()-()-()-()-()
       // l2 ()-()-()-()
       int carry=0;
       while(head1 && head2){
            int sum= head1->val + head2->val + carry;
            if(sum>9){
                carry=sum/10;
                sum=sum%10;
            }
            else {
                carry=0;
            }
            ListNode* node=new ListNode(sum);
            temp->next=node;
            temp=temp->next;
            head1=head1->next;
            head2=head2->next;
        }
       while(head1){
            int sum= head1->val + carry;
            if(sum>9){
                carry=sum/10;
                sum=sum%10;
            }
            else {
                carry=0;
            }
            ListNode* node=new ListNode(sum);
            temp->next=node;
            temp=temp->next;
            head1=head1->next;
        }
       while(head2){
            int sum= head2->val + carry;
            if(sum>9){
                carry=sum/10;
                sum=sum%10;
            }
            else {
                carry=0;
            }
            ListNode* node=new ListNode(sum);
            temp->next=node;
            temp=temp->next;
            head2=head2->next;
        }
        if(carry){
            ListNode* carrynode= new ListNode(carry);
            temp->next=carrynode;
        }
        //deleting -1
        temp=ans;
        ans=ans->next;
        delete temp;
        return ans;
    }
    ListNode* rev(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr= head;
        while(curr){
            ListNode* front=curr->next;
            curr->next=prev;
            // <-(prev) <-(curr) (front) 
            //.          (prev) (curr) ()
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head=rev(head);
        head=addTwoNumbers(head,head);
        head=rev(head);
        return head;
    }
};