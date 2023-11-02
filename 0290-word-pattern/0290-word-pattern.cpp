class Solution {
public:
    bool wordPattern(string pattern, string s) {
      vector<string>words;
        string str="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                words.push_back(str);
                str="";
            }
            else str+=s[i];
            }
        words.push_back(str);
        if(words.size()!=pattern.size()) return false;
        map<char,string> mp;
        map<string,int> check;
        for(auto i : words )
            check[i]=0;
        for(auto i=0 ;i<pattern.length();i++ ){
            if(mp.find(pattern[i])==mp.end()){
               if(check[words[i]]==0) {
                   mp[pattern[i]]=words[i];
                   check[words[i]]=1;
               }
            else return false;
            }
             
            else{
                if(mp[pattern[i]]!=words[i]) return false;
            }
        }
        return true;

            }
        };