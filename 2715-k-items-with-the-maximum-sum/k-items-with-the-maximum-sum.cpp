class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) {
            return k;
        }

        int sum = numOnes;
        k -= numOnes;

        while (k > 0 && numZeros > 0) {
            k--;
            numZeros--;
        }

        while (k > 0 && numNegOnes > 0) {
            sum--;
            k--;
            numNegOnes--;
        }

        return sum;
    }
};