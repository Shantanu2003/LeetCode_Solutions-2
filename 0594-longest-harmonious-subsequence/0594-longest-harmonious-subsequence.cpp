class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        for (int v : nums) {
            mp[v]++;
        }
        
        for (auto p : mp) {
            if (mp.find(p.first - 1) != mp.end()) {
                ans = max(ans, p.second + mp[p.first - 1]);
            }
        }
        
        return ans;
    }
};