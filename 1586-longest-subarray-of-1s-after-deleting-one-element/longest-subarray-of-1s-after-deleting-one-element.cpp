class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0, longestwindow = 0, start = 0;
        for(int i =0 ; i < nums.size(); i++){
            cnt += (nums[i] ==0);
            while(cnt > 1){
                    cnt -= (nums[start] == 0);
                    start++;
            }
            longestwindow = max(longestwindow, i-start);
        }
        return longestwindow;
    }
};