class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int j = cost.size()-3 ;j >=0; j--){
            cost[j] = cost[j]+min(cost[j+1],cost[j+2]) ;
        }
    return min(cost[0],cost[1]);

    }
};