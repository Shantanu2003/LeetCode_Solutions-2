class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string>mp;
        for(int  i = 0 ; i < names.size() ; i++){
            mp[heights[i]] = names[i];
        }
        
        vector<string>res;
        for(auto i : mp)
        res.push_back(i.second);

        reverse(res.begin(),res.end());
    return res;
    }
};