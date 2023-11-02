class Solution {
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps/2 + 1);
        vector<int>dp(arrLen, 0);
        vector<int>prevDp(arrLen, 0);
        prevDp[0] = 1;

        for(int  i = 1; i<= steps;i++){
            dp = vector(arrLen, 0);
                for(int j = arrLen-1; j>=0; j--){
                    int res = prevDp[j];

                    if(j>0){
                        res = (res+ prevDp[j-1])%1000000007;
                    }
                    if(j<arrLen-1){
                        res = (res+ prevDp[j+1])%1000000007;
                    }

                    dp[j] = res;
                }
            prevDp = dp;
        }
        return dp[0];
    }
};