class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int a=INT_MAX;
        int b=INT_MAX;
        for(int i:nums){
            if(i<=a){
                a=i;
            }
            else if(i<=b){
                b=i;
            }
            else return true;
        }
        return false;
    }
};