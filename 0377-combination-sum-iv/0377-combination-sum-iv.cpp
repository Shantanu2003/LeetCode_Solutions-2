class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<unsigned int>dp(target+1);
       dp[0] = 1;
       int i,j;
       for(i = 1 ; i< target+1;i++){
           for(j =0 ; j< nums.size(); j++)
           if(i-nums[j]>=0){
               dp[i] += dp[i-nums[j]];
           }
       }
       return dp[target];
    }
};
