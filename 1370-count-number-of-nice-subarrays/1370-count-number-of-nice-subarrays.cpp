class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for (int &num : nums) {
            num = (num % 2 == 0) ? 0 : 1;
        }

        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  
        int currentSum = 0;
        int count = 0;

        for (int num : nums) {
            currentSum += num;
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};
