class CustomStack {
public:
    vector<int> st;
    int size;
    int curr;
    CustomStack(int maxSize) {
        size=maxSize;
        curr=-1;
        st.resize(maxSize,0);
    }
    
    void push(int x) {
        if(curr==size-1) return;
        curr++;
        st[curr]=x;
    }
    
    int pop() {
        if(curr==-1) return -1;
        int a=st[curr];
        curr--;
        return a;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<k && i<=curr;i++){
            st[i]=st[i]+val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */