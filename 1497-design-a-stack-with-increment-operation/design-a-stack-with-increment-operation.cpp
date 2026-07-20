class CustomStack {
public:
    stack<int> st;
    int size;
    int curr;
    CustomStack(int maxSize) {
        size=maxSize;
        curr=0;
    }
    
    void push(int x) {
        if(curr==size) return;
        curr++;
        st.push(x);
    }
    
    int pop() {
        if(st.empty()) return -1;
        int a=st.top();st.pop();
        curr--;
        return a;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty() && k--){
            st.push(val+temp.top());
            temp.pop();
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */