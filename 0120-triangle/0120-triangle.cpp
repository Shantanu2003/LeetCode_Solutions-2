class Solution {
public:
    int helper(vector<vector<int>>&grid, vector<vector<int>>&dp, int row, int col, int n){
        if(row == n-1)
        return grid[row][col];;

        if(dp[row][col] != -1)
        return dp[row][col];

        int down = helper(grid,dp,row+1, col, n);
        int right = helper(grid, dp,row+1,col+1,n);

        dp[row][col] = grid[row][col] + min(down,right);

        return dp[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return helper(triangle, dp, 0,0,n);
    }
};