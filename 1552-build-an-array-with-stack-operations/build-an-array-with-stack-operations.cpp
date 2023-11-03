class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        
        int j = 1;  // Initialize j to 1, as the target array starts from 1
        
        for (int i = 1; i <= n && j <= target.size(); i++) {
            ans.push_back("Push");
            
            if (target[j - 1] != i) {
                ans.push_back("Pop");
            } else {
                j++;
            }
        }

        return ans;
    }
};