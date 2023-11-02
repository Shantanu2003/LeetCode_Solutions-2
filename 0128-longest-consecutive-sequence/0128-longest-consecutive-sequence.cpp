class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    if(n == 0){
      return  0;
    }
    int max1= 1, count = 1;
    for(int  i = 1 ; i  < n ; i++){
    if (nums[i] != nums[i-1]) {
      if (nums[i] == nums[i - 1] + 1) {
        count++;
      } 
      else {
        max1 = std::max(max1, count);
        count = 1;
      }
    }
    }
    return std::max(max1, count);
    }
};