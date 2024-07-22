class Solution {
public: 
    vector<int> solve(vector<vector<int>>edges, int k){
        vector<vector<int>>adj(k+1);
         vector<int>indegree(k+1), res;
        for(auto i: edges){
            int x = i[0];
            int y = i[1];

            adj[x].push_back(y);
            indegree[y]++;
        }

        queue<int>q;
        for(int i = 1 ; i <= k ; i++){
            if(indegree[i] == 0)
            q.push(i);
        }

        while(!q.empty()){
             int top = q.front();
             q.pop();
             res.push_back(top);

             k--;

             for(auto i: adj[top]){
                indegree[i]--;
                if(indegree[i] == 0)
                q.push(i);
             }
        }

        if(k != 0)return{};
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>adj(k, vector<int>(k, 0));

        vector<int>orderRows = solve(rowConditions, k);
        vector<int>orderColumns = solve(colConditions, k);

        if (orderRows.empty() or orderColumns.empty()) return {};


        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;   
    }
};