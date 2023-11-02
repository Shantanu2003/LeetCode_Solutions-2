class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int  max= 0;
        if(nums.size()<2) return 0;
        else{
            sort(nums.begin(),nums.end());
            for(int i = 1 ; i < nums.size() ; i++){
                int diff = 0;
                diff = nums[i]- nums[i-1];
                if(max < diff) max = diff;
            }
        }
        return max;
    }
};