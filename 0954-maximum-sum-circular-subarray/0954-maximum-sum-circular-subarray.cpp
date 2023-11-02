class Solution {
private:
int minSum(vector<int>& nums){
    int ans = INT_MAX;
    int sum = 0;

    for (int  i = 0 ; i< nums.size() ; i++)  {
      sum = min(nums[i], sum + nums[i]);;
      ans = min(ans, sum);
    }

    return ans;
}
int maxSum(vector<int>& nums){
    int ans = INT_MIN;
    int sum = 0;

    for (int  i = 0 ; i< nums.size() ; i++)  {
      sum = max(nums[i], sum + nums[i]);
      ans = max(ans, sum);
    }

    return ans;
}
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    long long int totalSum =0;
     for(int j = 0; j<nums.size(); j++){
         totalSum += nums[j];
     }
    int maxS = maxSum(nums);
    int minS = minSum(nums);

    if(minS== totalSum)
    return maxS;

    int ans = totalSum-minS;
    return max(maxS, ans);
    }
};