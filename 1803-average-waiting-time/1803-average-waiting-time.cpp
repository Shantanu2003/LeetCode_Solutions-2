class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long ans = 0;
        long long preFinish = customers[0][0];

        int n = customers.size();

        for(int i = 0; i < n ; i++){
            if(preFinish < customers[i][0]){
                preFinish = customers[i][0] + customers[i][1];
                ans += (preFinish - customers[i][0]);
            }

            else{
                preFinish += customers[i][1];
                ans += (preFinish - customers[i][0]);
            }
        }

        return double(ans)/n;

    }
};