class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col){
        if(row == 0 && col == 0)
        return grid[0][0];

        if(row < 0 || col < 0)
        return INT_MAX;

        if(dp[row][col] != -1)
        return dp[row][col];

        int up = helper(grid, dp, row-1 ,col);
        int left = helper(grid,dp,row, col-1);

        dp[row][col] = grid[row][col] +  min(up,left);

        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));

        return helper(grid,dp, n-1, m-1);
    }
};