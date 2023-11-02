class Solution {
private:
   int solve(int n){
       vector<int>dp(n+1, INT_MAX);
       dp[0]=0;
       for(int i = 1 ; i <= n ; i++){
        for(int  j = 1 ; j*j <= i ; j++){
            if(i-j*j>=0)
            dp[i] = min(dp[i], 1 + dp[i- (j*j)]);
        }
       }
        return dp[n];

   }
public:
    int numSquares(int n) {
        if(ceil((double)sqrt(n)) == floor((double)sqrt(n)))
        return  1;

        if(n == 0)
        return  0;

        return solve(n);
    }
};