class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int,int>mp;

        for(char c: s){
            mp[c]++;
        }

        int ans= 0;

        for(auto i : mp){
            if(i.second %2 == 0)
            ans += 2;
            else
            ans += 1;
        }

        return ans;
    }
};