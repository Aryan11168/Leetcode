class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg=0;
        double cnt=0;
        int n=customers.size();
        int start=customers[0][0];
        int finish=start+customers[0][1];
        cnt++;
        avg+=finish-start;
        start=finish;
        for(int i=1;i<n;i++){
            int arrive=customers[i][0];
            int time=customers[i][1];
            if(start>=arrive){
                finish=start+time;
            }
            else {
                start=arrive;
                finish=start+time;
            }
            cnt++;
            avg+=finish-arrive;
            start=finish;
        }
        return avg/cnt;


    }
};