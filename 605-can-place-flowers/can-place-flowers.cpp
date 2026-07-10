class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        int s=flowerbed.size();
        if(s==1){
            if(flowerbed[0]==0) cnt++;
            return cnt>=n;
        }
        for(int i=0;i<s;i++){
            if(flowerbed[i]==1) continue;
            if(i==0 && flowerbed[i+1]==0 && flowerbed[i]==0){
                flowerbed[i]=1;
                cnt++;
            }
            else if(i==s-1 && flowerbed[i]==0 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                cnt++;
            }
            else if(i>0 && i<s-1 && flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                cnt++;
            }
        }
        return cnt>=n;
    }
};