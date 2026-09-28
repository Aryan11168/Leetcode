class Solution {
public:
int maxDepth(string s) {
    int cnt=0;
    int maxDepth=0;
    for(char ch:s){
        if(ch=='(') cnt++;
        else if(ch==')') {
            maxDepth=max(cnt,maxDepth);
            cnt--;
        }
        
    }
    return maxDepth;
}

};