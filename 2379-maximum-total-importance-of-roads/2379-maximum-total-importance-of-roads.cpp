class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>mp(n,0);

        for(int i = 0; i < roads.size() ; i++){
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }

        vector<pair<long long,long long>>frequency;
        for (int i = 0; i < mp.size(); ++i) {
            frequency.emplace_back(i, mp[i]);
        }

        sort(frequency.begin(), frequency.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;});
        long long res = 0;
        int j = n;
        for(auto i : frequency){
           res += (i.second*j);
           j--;
        }

    return res;
        

    }
};