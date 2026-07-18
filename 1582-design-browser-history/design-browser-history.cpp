struct StringListNode{
    string val;
    StringListNode* next;
    StringListNode* prev;
    StringListNode(string v){
        val=v;
        next=nullptr;
        prev=nullptr;
    }
};
class BrowserHistory {
private:
StringListNode* head;
StringListNode* curr;
public:
    BrowserHistory(string homepage) {
    head = new StringListNode(homepage);
    head->prev = nullptr;
    head->next = nullptr;
    curr = head;
}
    void visit(string url) {
        //a-b-c-d ,current is at b , to add e we have to delete c,d
        if(curr->next){
            StringListNode* temp=curr->next;
            while(temp!=NULL){
                StringListNode*nextnode=temp->next;
                delete(temp);
                temp=nextnode;
            }
        }
        StringListNode* node= new StringListNode(url);
        node->prev =curr;
        curr->next=node;
        curr=node;
    }
    
    string back(int steps) {
        while(steps--){  //jab tak steps bache hain
            if(curr->prev){    //and current ka prev bhi exist krra h
                curr=curr->prev; // peeche jaate jao
            }
            else break;   //prev nahi exist krra toh wahi ruk jao
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps--){
            if(curr->next){
                curr=curr->next;
            }
            else break;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */