class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int>s;
        vector<int>res;
        for(int i = 0 ; i < matrix.size() ; i++){
            int mini = INT_MAX;
            for(int j = 0 ; j < matrix[0].size() ; j++){
               mini = min(mini, matrix[i][j]);
            }
            s.insert(mini);
        }

        for(int i = 0 ; i < matrix[0].size() ; i++){
            int maxi = INT_MIN;
            for(int j = 0 ; j < matrix.size() ; j++){
               maxi = max(maxi, matrix[j][i]);
            }
            if(s.find(maxi) != s.end())
            res.push_back(maxi);
        }


      return res;
    }
};