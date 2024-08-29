class Solution {
public:
    void bfs(vector<vector<int>>& stones, vector<int>& visited, int index, int n) {
        queue<int> q;
        q.push(index);
        visited[index] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < n; ++i) {
                // If not visited and either row or column matches
                if (!visited[i] && (stones[curr][0] == stones[i][0] || stones[curr][1] == stones[i][1])) {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n, 0);

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++count;
                bfs(stones, visited, i, n);
            }
        }

        // The answer is total stones minus the number of connected components
        return n - count;
    }
};
