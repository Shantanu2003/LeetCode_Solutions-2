class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(n + 1, 0);
        int count = 0;
        unordered_map<long long, int> mp;
        long long cumulativeSum = 0;

        for (int i = 0; i < n; i++) {
            cumulativeSum += nums[i];
            if (cumulativeSum == k) {
                count++;
            }
            if (mp.find(cumulativeSum - k) != mp.end()) {
                count += mp[cumulativeSum - k];
            }
            mp[cumulativeSum]++;
        }

        return count;
    }
};
