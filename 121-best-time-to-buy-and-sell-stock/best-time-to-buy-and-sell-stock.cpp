class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int diff = 0;
    int maxi = prices[0];
    for (int i = 1; i <prices.size(); i++) {
         if(maxi>prices[i]){
             maxi = prices[i];
         } 
         else if(prices[i]-maxi>diff){
             diff = prices[i]-maxi;
         }
         }
         return diff;
    }
};