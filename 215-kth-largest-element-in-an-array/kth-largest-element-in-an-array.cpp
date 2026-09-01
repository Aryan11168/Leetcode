class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(), nums.end());
        //int n= nums.size();
        //return nums[n-k];
        vector<int>v1(10001);
        vector<int>v2(10001);
        for(int i =0; i<nums.size(); i++){
            if(nums[i]>=0){
                v1[nums[i]]++;
            }
            else{
                v2[abs(nums[i])]++;
            }
        }
        for(int i= 1e4; i>=0; i--){
            if(v1[i]==0) continue;
            else{
                if(v1[i]>=k){
                     return i;
                }
                else{
                    k-=v1[i];
                }
            }
        }
        for(int i =0; i<=1e4; i++){
            if(v2[i]==0) continue;
            else{
                if(v2[i]>=k){
                     return -i;
                }
                else{
                    k-=v2[i];
                }
            }
        }
        return -1;
    }
};