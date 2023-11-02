class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans= "";
       sort(strs.begin(),strs.end());
       int n = strs.size();
       string f = strs[0], l = strs[n-1];
       int size;
       if(f.size()>l.size())
       size = l.size();
       else
       size = f.size();
       for(int i = 0; i<size; i++){
           if(f[i]!=l[i])
           return ans;

           ans+=f[i];
       }
       return ans;
    }
};