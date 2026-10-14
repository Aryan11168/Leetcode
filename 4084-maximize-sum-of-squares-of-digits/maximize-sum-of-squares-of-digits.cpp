class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        int drevantor = sum; 
        if (sum > 9 * num || sum < 0) return ans;
        vector<int> digits(num, 0);
        for (int i = 0; i < num; i++) {
            if (sum >= 9) {
                digits[i] = 9;
                sum -= 9;
            } else {
                digits[i] = sum;
                sum = 0;
            }
        }
        if (sum != 0) return "";
        for (int d : digits) ans += char('0' + d);
        return ans;
    }
};