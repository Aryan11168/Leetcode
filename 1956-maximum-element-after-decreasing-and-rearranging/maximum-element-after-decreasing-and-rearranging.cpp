class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int th=1;
        for(int i=1;i<arr.size();i++){
            th=min(th+1,arr[i]);
        }
        return th;
    }
};