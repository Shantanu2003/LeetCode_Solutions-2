class Solution {
public: 
     void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited);
            }
        }
    }

    int helper(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int islands = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    islands++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int v= n*m;
        
        if(helper(grid) > 1)
        return 0;

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) count++;
            }
        }

        if(count == 1)
        return 1;

        else if(count == 0)
        return 0;



        for(int i = 0 ; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(helper(grid) > 1)
                    return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};