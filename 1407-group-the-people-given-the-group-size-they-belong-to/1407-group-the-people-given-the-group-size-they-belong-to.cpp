class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        vector<int> mp[groupSizes.size()+1];
        for(int i = 0 ; i < groupSizes.size() ; i++){
           mp[groupSizes[i]].push_back(i);

           if(mp[groupSizes[i]].size() == groupSizes[i]){
               ans.push_back({mp[groupSizes[i]]});
               mp[groupSizes[i]].clear();
           }
        }
        return ans;
    }
};