class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int maxi = 0;
    int cnt0 = 0;
    
    for(int i = 0, j = 0; i < nums.size(); i++){
        // if we find 0 increment count
        if(nums[i] == 0){
            cnt0++;
        }


       // if we encounter that cnt0 is greater than k, increment the j counter
        while(cnt0 > k){
           if(nums[j] == 0){
               cnt0--;
           }
           j++;
        }

        maxi = max(maxi, i-j+1);
    }

    return maxi;
    }
};