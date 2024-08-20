class Solution {
public:
    int helper(vector<int>& suffix,vector<vector<int>>& dp, int index, int m){
          if(index + 2*m >= suffix.size())
          return suffix[index];

          if(dp[index][m] != -1)
          return dp[index][m];

          int maxi = INT_MAX;

          for(int i = 1; i <= 2*m ; i++){
            int val = helper(suffix,dp, index+i, max(m,i));
            maxi = min(maxi,val);
          }

          dp[index][m] = suffix[index] - maxi;

          return dp[index][m];

    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int res = 0;
        if(n <= 2){
            for(int i = 0; i < n ; i++){
               res += piles[i];
            }
        }

        vector<int>suffix(n);
        suffix[n-1] = piles[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] = piles[i] + suffix[i+1];
        }


         vector<vector<int>>dp(n, vector<int>(n,-1));

         res = helper(suffix,dp,0,1);

         return res;
    }
};