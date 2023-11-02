class Solution {
public:
    bool search(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int lo = 0, hi = int(nums.size()) - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
            lo = mid + 1;
        else
            hi = mid;
    }
    if(lo == hi && nums[lo] == target) return true;
    else
    return false;
    }
};