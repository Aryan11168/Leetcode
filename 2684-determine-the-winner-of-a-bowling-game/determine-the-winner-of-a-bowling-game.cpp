class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1=0;
        int s2=0;
        int n=player1.size();
        for(int i=0;i<n;i++){
            if(i-1>=0 && player1[i-1]==10){
                s1+=player1[i]*2;
            }
            else if(i-2>=0 && player1[i-2]==10){
                s1+=player1[i]*2;
            }
            else s1+=player1[i];
        }
        for(int i=0;i<n;i++){
            if(i-1>=0 && player2[i-1]==10){
                s2+=player2[i]*2;
            }
            else if(i-2>=0 && player2[i-2]==10){
                s2+=player2[i]*2;
            }
            else s2+=player2[i];
        }
        return s1==s2?0:s1>s2?1:2;
    }
};