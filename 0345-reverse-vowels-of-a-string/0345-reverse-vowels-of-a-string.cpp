class Solution {
public:
    string reverseVowels(string s) {
        vector<int>ans;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i]=='u' ||
             s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i]=='U' ){
                ans.push_back(i);
             }
        }
        for(int  i =0 ; i<ans.size()/2 ; i++){
           swap(s[ans[i]],s[ans[ans.size()-i-1]]);
        }
        return s;
    }
};