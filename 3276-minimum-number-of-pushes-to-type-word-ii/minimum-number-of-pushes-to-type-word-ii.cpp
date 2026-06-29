class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char c:word) freq[c-'a']++;
        priority_queue<int> q;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                q.push(freq[i]);
            }
        }
        int cnt=0;
        int push=0;
        while(!q.empty()){
            int f=q.top();q.pop();
            cnt++;
            int mul=(cnt-1)/8;
            push+=f*(mul+1);
        }
        return push;
    }
};