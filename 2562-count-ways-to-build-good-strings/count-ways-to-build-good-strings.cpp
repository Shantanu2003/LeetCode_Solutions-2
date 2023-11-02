#define mod 1000000007
class Solution {
public:
int countGoodStrings(int low, int high, int zero, int one) {
vector<int> dp(high+1, 0);
dp[0] = 1;
int ans = 0;
for(int len = 1; len <= high; len++){
if(len >= zero)
dp[len] = dp[len-zero];
if(len >= one)
dp[len] = (dp[len] + dp[len - one])%mod;
if(len >= low)
ans = (ans + dp[len])%mod;
}
return ans;
}
};