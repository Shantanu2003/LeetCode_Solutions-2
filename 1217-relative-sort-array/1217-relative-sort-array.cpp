class Solution {
public:
bool Comp(int a, int b, const unordered_map<int,int>&mp) 
{ 
    if(mp.find(a) != mp.end() && mp.find(b) != mp.end())
    return mp.at(a) < mp.at(b);

    else if(mp.find(a) != mp.end())
    return true;

    else if(mp.find(b) != mp.end())
    return false;

    return a<b;
} 
        unordered_map<int,int>mp;

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        for(int i = 0 ; i < arr2.size() ; i++)
        mp[arr2[i]] = i;

        auto compLambda = [this](int a, int b) {
            return Comp(a, b, mp);
        };

        
        sort(arr1.begin(), arr1.end(),compLambda);

        return arr1;
    }
};