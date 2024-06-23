class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int left = 0, right = 0;
        int oddCount = 0;

        while (right < n) {
            if (nums[right] % 2 != 0) {
                k--;
                oddCount = 0;
            }
            
            while (k == 0) {
                k += nums[left] % 2;
                left++;
                oddCount++;
            }

            count += oddCount;
            right++;
        }

        return count;
    }
};