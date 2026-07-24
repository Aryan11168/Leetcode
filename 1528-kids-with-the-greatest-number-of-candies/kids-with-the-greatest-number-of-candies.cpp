class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      int maxi=candies[0];
      for(int i:candies){
        maxi=max(maxi,i);
      }
      vector<bool> ans;
      for(int i:candies){
        if(i+extraCandies>=maxi) ans.push_back(true);
        else ans.push_back(false);
      }
      return ans;
    }
};