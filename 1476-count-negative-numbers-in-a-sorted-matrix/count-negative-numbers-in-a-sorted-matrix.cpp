class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count  = 0;
        for(int i = 0 ; i<grid.size() * grid[0].size(); i ++){
                long row = i/grid[0].size();
                long columns = i % grid[0].size();
                if(grid[row][columns] < 0){
                    count++;
                }
        }
        return count;
    }
};