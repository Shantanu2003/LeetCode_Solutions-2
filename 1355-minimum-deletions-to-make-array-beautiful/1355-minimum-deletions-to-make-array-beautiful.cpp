class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        int i=0; int ans=0;
        while(i < n-1) {
            if(nums[i] == nums[i+1]) i++, ans++;
            else i+=2;
        }
        if(i == n-1) return ans+1;
        return ans;
    }
};