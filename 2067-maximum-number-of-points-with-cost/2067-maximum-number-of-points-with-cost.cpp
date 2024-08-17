class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        // DP array to store max points for each cell
        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        // Initialize the first row
        for (int j = 0; j < m; j++) {
            dp[0][j] = points[0][j];
        }

        // Iterate over each row starting from the second
        for (int i = 1; i < n; i++) {
            vector<long long> leftMax(m, 0), rightMax(m, 0);

            // Calculate max values from the left to right (for reducing the penalty)
            leftMax[0] = dp[i-1][0];
            for (int j = 1; j < m; j++) {
                leftMax[j] = max(leftMax[j-1] - 1, dp[i-1][j]);
            }

            // Calculate max values from the right to left (for reducing the penalty)
            rightMax[m-1] = dp[i-1][m-1];
            for (int j = m-2; j >= 0; j--) {
                rightMax[j] = max(rightMax[j+1] - 1, dp[i-1][j]);
            }

            // Update the dp table for the current row
            for (int j = 0; j < m; j++) {
                dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }

        // The answer is the maximum value in the last row
        long long ans = LLONG_MIN;
        for (int j = 0; j < m; j++) {
            ans = max(ans, dp[n-1][j]);
        }

        return ans;
    }
};
