class Solution {
public:
    int minDifference(vector<int>& nums) {
        int numsSize = nums.size();

        // If the array has 4 or fewer elements, return 0
        if (numsSize <= 4) return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // Four scenarios to compute the minimum difference
        for (int left = 0, right = numsSize - 4; left < 4; left++, right++) {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};
/*


1 5 0 10 14 8
0 1 5 8 10 14

5 3 2 4
2 3 4 5

6 6 0 1 1 4 6
0 1 1 4 6 6 6


82 81 95 75 20
20 75 81 82 95



*/

 


