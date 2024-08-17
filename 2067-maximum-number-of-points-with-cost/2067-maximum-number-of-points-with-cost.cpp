class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<long long>previous(m);
        for(int i = 0 ; i < m ; i++)
        previous[i] = points[0][i];

        for(int j = 0 ; j < n-1 ; j++){
             vector<long long>left(m);
             vector<long long>right(m);
             vector<long long>current(m);

             left[0] = previous[0];
             for(int i = 1 ; i < m ; i++){
                 left[i] = max(left[i-1] - 1, previous[i]);
             }
             right[m-1] = previous[m-1];
             for(int i = m-2 ; i >= 0 ; i--){
                 right[i] = max(right[i+1] - 1, previous[i]);
             }

             for(int i = 0 ; i < m ; i++){
                current[i] = points[j+1][i] + max(left[i],right[i]);
             }
        previous = current;

        }
        long long ans = 0;

        for(int  i = 0 ; i < m ; i++){
            ans = max(ans, previous[i]);
        }

        return ans;
    }
};