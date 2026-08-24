class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int len=details[i].length();
            string temp=details[i].substr(len-4,2);
            int age=stoi(temp);
            if(age>60) cnt++;
        }
        return cnt;
    }
};