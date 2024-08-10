class Solution {
public:
    vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(vector<vector<int>>&grid1, int row , int col){
        if(row>= 0 && col >= 0 && row < grid1.size() && col < grid1.size() && grid1[row][col] == 0)
        return true;

        return false;
    }
    void flodfill(vector<vector<int>>&grid1, int row , int col){
        queue<pair<int,int>>q;
        q.push(make_pair(row,col));

        grid1[row][col] = 1;


        while(!q.empty()){
          auto top = q.front();
          q.pop();

          for(auto i : dir){
            int newRow = i[0] + top.first;
            int newCol = i[1] + top.second;


            if(isValid(grid1,newRow,newCol)){
                grid1[newRow][newCol] = 1;
                q.push(make_pair(newRow,newCol));
            }
          }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
         int size = grid.size();

         vector<vector<int>>grid1(3*size, vector<int>(3*size,0));
         for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid.size() ; j++){
                int baseRow = 3*i;
                int baseCol = 3*j;

                if(grid[i][j] == '\\'){
                    grid1[baseRow][baseCol] = 1;
                    grid1[baseRow+1][baseCol+1] = 1;
                    grid1[baseRow+2][baseCol+2] = 1;
                }
                else if(grid[i][j] == '/'){
                    grid1[baseRow][baseCol+2] = 1;
                    grid1[baseRow+1][baseCol+1] = 1;
                    grid1[baseRow+2][baseCol] = 1;
                }
            }
         }

         int count = 0;
         for(int  i = 0 ; i < grid1.size() ; i++){
            for(int j = 0 ; j < grid1.size() ; j++){
                if(grid1[i][j] == 0){
                    flodfill(grid1,i,j);
                    count++;
                }
            }
         }
    return count;
    }
};