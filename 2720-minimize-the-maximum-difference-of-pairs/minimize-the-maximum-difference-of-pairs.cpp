class Solution {
public:
    int countValidPairs(vector<int>& nums, int threshold){
        int count = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i]<=threshold){
                count++;
                i++;
            }
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
    
    sort(nums.begin(),nums.end());
    int n= nums.size();
    int left =0, right = nums[n-1]-nums[0];
    while(left < right){
        int mid = left+ (right - left)/2;


        if(countValidPairs(nums, mid) >=p) {
        right = mid;
        }
        else{
        left = mid+1;
    }
    }
    return left;
    }
};