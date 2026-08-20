class Solution {
public:
    void produce(vector<int> &ans,int prev,int n){
        if(ans.size() == n) return;
        for(int i = 0; i <= 9; i++){
            int curr = prev*10 + i;
            if(0 < curr && curr <= n){
                ans.push_back(curr);
            }
            if(0 < curr && curr*10 <= n){
                produce(ans,curr,n);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        produce(ans,0,n);
        return ans;
    }
};