class Solution {
public:
    void gen(string temp,vector<int>& allSeq){
        allSeq.push_back(stoi(temp));
        char c=temp.back();
        if(c=='9') return;
        temp.push_back(c+1);
        gen(temp,allSeq);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> allSeq;
        string temp="";
        for(int i=1;i<=9;i++){
            temp+=to_string(i);
            gen(temp,allSeq);
            temp.pop_back();
        }
        sort(allSeq.begin(),allSeq.end());
        vector<int> ans;
        for(int i:allSeq){
            if(i>=low && i<=high) ans.push_back(i);
        }
        return ans;
    }
};