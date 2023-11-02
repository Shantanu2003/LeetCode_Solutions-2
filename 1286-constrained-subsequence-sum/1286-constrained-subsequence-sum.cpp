class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> dp(n, 0);

    std::deque<int> maxValues;

    dp[0] = nums[0];
    maxValues.push_back(0);

    for (int i = 1; i < n; i++) {
        while (maxValues.front() < i - k) {
            maxValues.pop_front();
        }

        dp[i] = std::max(nums[i], nums[i] + dp[maxValues.front()]);
        
        while (!maxValues.empty() && dp[i] >= dp[maxValues.back()]) {
            maxValues.pop_back();
        }

        maxValues.push_back(i);
    }

    return *std::max_element(dp.begin(), dp.end());     
}
};