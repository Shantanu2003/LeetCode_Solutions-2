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