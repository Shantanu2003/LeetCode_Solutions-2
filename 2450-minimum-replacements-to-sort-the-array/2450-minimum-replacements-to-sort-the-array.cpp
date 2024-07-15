class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long answer = 0;
        long long nums_elements;
        for(int  i = nums.size()-2; i>=0; i--){
            if(nums[i]<= nums[i+1]){
                continue;
            }
            long long nums_elements = ceil((nums[i] + nums[i + 1] - 1LL) / (nums[i + 1]));
            answer += nums_elements-1;

            nums[i] = nums[i]/nums_elements;
        }
        return answer;
    }
};
// 9 > 3
// 9 + 3  - 1/ 3
// 4 
// answer = 3

// i = 9 / 4 = 2

// 3 2 3

// 3 + 2 -1 / 2 = 2
// aswer = 4
