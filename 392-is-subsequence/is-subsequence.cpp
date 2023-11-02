class Solution {
public:
    int solve(string s, string t,int i, int j){
        if(i==s.length()|| j==t.length())
            return 0;
        if(s[i]== t[j])
            return 1+ solve(s,t,i+1,j+1);
        else
            return solve(s,t,i,j+1);
    }
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        int ans = solve(s,t,i,j);
        if(s.length()==ans)
            return 1;
        else
            return 0;
    }
};