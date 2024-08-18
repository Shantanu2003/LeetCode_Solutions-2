class Solution {
public:
vector<int>dr = {-1,0};
vector<int>dc = {0,-1};
bool isValid(vector<vector<int>>& grid, int row, int col, int n ,int m){
    if(row >= 0 && col >= 0 && row < n && col < m && grid[row][col] != 1)
    return true;

    return false;
}
    int helper(vector<vector<int>>& grid, int row, int col, int n , int m, vector<vector<int>>& dp){
        if (grid[row][col] == 1) {
            return 0;
        }

        if(row == 0 && col == 0){
            return 1;
        }

        if(row < 0 || col < 0)
        return 0;

        if(dp[row][col] != -1)
        return dp[row][col];

        dp[row][col] = 0; 
        
        for(int i = 0 ; i < 2 ; i++){
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            
            if(isValid(grid, newRow, newCol, n ,m)){
               dp[row][col] += helper(grid, newRow, newCol,  n ,m ,dp);
            }
        }


        return dp[row][col];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));

        return helper(grid, n-1,m-1, n ,m,dp);
    }
};