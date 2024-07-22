class Solution {
public:
    // int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
    //     if(i >= days.size())
    //     return 0;

    //     if(dp[i] != -1)
    //     return dp[i];

    //     int res1 = costs[0] + solve(days, costs, i + 1, dp);

    //     int j;

    //     for(j = i; j < days.size() && days[j] < days[i] + 7 ; j++);

    //     int res2 = costs[1] + solve(days, costs, j,dp);

    //     for(j = i; j < days.size() && days[j] < days[i] + 30 ; j++);

    //     int res3 = costs[2] + solve(days, costs, j,dp);

    //     dp[i] = min(res1,min(res2,res3));
        
    //     return dp[i];

    // }

    int solve(vector<int>& days, vector<int>& costs, int i){
        int n = days.size();
        vector<int>dp(n+1, INT_MAX);
        
        dp[n] = 0;

        for(int  k = n-1 ; k >= 0 ; k--){

            int res1 = costs[0] + dp[k+1];

            int j;

            for(j = k; j < days.size() && days[j] < days[k] + 7 ; j++);

            int res2 = costs[1] + dp[j];

            for(j = k; j < days.size() && days[j] < days[k] + 30 ; j++);

            int res3  = costs[2] + dp[j]; 

            dp[k] = min(res1,min(res2,res3));

        }
        
        return dp[0];

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days,costs,0);
    }
};