class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ans(n+1, 0);
        ans[1] = 1;
   
        int i2 = 1, i3 = 1, i5 = 1; // Pointers for multiples of 2, 3, and 5

        for (int i = 2; i <= n; ++i) {
            int nextUgly = min({2 * ans[i2], 3 * ans[i3], 5 * ans[i5]});
            ans[i] = nextUgly;

            // Update pointers based on the chosen ugly number
            if (nextUgly == 2 * ans[i2]) i2++;
            if (nextUgly == 3 * ans[i3]) i3++;
            if (nextUgly == 5 * ans[i5]) i5++;
        }

        return ans[n];
    }
};