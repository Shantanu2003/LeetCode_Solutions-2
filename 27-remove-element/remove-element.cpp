class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end = nums.size()-1;
        int ans= 0;
        for(int  i = 0 ; i < nums.size(); i++){
            if(nums[i] != val){
                   nums[ans] = nums[i];
                   ans++;
            }
        }
        return ans;
    }
};