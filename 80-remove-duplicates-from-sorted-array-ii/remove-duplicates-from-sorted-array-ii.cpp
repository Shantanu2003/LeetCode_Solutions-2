class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                if(count<2){
                count++;
                j++;
                nums[j] = nums[i];
            }
            }
            else{
                count = 1;
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};