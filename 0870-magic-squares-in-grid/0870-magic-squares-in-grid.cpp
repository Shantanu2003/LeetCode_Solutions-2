class Solution {
public:
bool helper(int row, int col, vector<vector<int>>& grid){
        bool seen[10] = {false};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9) return false;
                if (seen[num]) return false;
                seen[num] = true;
            }
        }

        int diagonal1 =grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal2 =grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

        if (diagonal1 != diagonal2) return false;

        int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int row2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int row3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];

        
        int col1 = grid[row+1][col] + grid[row][col] + grid[row+2][col];
        int col2 = grid[row+1][col+1] + grid[row][col+1] + grid[row+2][col+1];
        int col3 = grid[row+1][col+2] + grid[row][col+2] + grid[row+2][col+2];

        if(col1 != diagonal1 || col2 != diagonal1 || col3 != diagonal2)
        return false;

        
        if(row1 != diagonal1 || row2 != diagonal1 || row3 != diagonal2)
        return false;


        return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if((i+2) < grid.size() && (j+2) < grid[0].size() && helper(i,j,grid))
                ans++;
            }
        }

        return ans;
    }
};