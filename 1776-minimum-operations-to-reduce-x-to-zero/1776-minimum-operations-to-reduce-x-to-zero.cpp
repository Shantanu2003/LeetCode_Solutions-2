class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    int target = accumulate(nums.begin(), nums.end(), 0) - x;
    int n = nums.size();
    int left = 0;
    int current_sum = 0;
    int min_operations = 0;

    if (target == 0) return n;

    for (int right = 0; right < n; ++right) {
        current_sum += nums[right];

        while (current_sum > target && left<=right) {
            current_sum -= nums[left];
            ++left;
        }
        if(current_sum== target)
        min_operations = max(min_operations, right - left + 1);

    }

    return min_operations ? n - min_operations : -1;
    }
};