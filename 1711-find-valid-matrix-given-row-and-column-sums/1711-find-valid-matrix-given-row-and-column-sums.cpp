class Solution {
public:
    void solve(vector<int>& rowSum, vector<int>& colSum, vector<vector<int>>& res, int i, int j) {
        if (i == rowSum.size() || j == colSum.size()) {
            return;
        }

        int val = min(rowSum[i], colSum[j]);
        res[i][j] = val;
        rowSum[i] -= val;
        colSum[j] -= val;

        if (rowSum[i] == 0 && i < rowSum.size() - 1) {
            solve(rowSum, colSum, res, i + 1, j);
        } else if (colSum[j] == 0 && j < colSum.size() - 1) {
            solve(rowSum, colSum, res, i, j + 1);
        } else {
            solve(rowSum, colSum, res, i, j+1);
        }
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int col = colSum.size();
        vector<vector<int>>res(n, vector<int>(col));

        solve(rowSum,colSum,res,0,0);

        return res;
    }
};
// 5 0 0
// 1 1 5
// 2 5 3