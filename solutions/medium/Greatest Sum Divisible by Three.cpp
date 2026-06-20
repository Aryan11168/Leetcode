// Title: Greatest Sum Divisible by Three
            // Difficulty: Medium
            // Language: C++
            // Link: https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        vector<int> a;
        vector<int> b;
        for(int i:nums){
            int t=i%3;
            sum+=i;
            if(t==1) a.push_back(i);
            else if(t==2) b.push_back(i);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(sum%3==0) return sum;
