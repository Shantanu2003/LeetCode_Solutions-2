class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        long long x = num/3;
        if(num % 3 != 0) return ans;
        else{
        ans.push_back(x-1);
        ans.push_back(x);
        ans.push_back(x+1);
        sort(ans.begin(), ans.end());
        }
        return ans;
    }
};