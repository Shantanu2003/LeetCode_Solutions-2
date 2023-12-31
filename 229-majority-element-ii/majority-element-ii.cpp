class Solution {
public:
   vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto it : m){
            if(it.second > n/3){
                v.push_back(it.first);
            } 
        }
        return v;
    }
};