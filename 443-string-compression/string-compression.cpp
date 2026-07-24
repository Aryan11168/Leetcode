class Solution {
public:
    int compress(vector<char>& chars) {
        int a=0;
        int i=0;
        int n=chars.size();
        int d=0;
        while(i<n){
            d++;
            char c=chars[i];
            int cnt=0;
            while(i<n && c==chars[i]){
                i++;
                cnt++;
            }
            chars[a++]=c;
            if(cnt>1){
                string temp=to_string(cnt);
                for(char t:temp){
                    chars[a++]=t;
                    d++;
                }
            }
            
        }
        return d;
    }
};