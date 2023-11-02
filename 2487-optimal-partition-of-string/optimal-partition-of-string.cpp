class Solution {
public:
    int partitionString(string s) {
        vector<int> ans(26, -1);
        int count = 1;
        int start = 0;
        for(int  i = 0 ; i  < s.size() ; i++){
            if(ans[s[i] -'a'] >= start){
                count++;
                start = i;
            }
            ans[s[i]-'a'] =i;
        }
        return count;
    }
};