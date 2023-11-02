class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;
        string res="";  
        for (auto ch : s)
            if (isdigit(ch)) size *= int(ch) - 48;
            else ++size;
        for (int i = s.length() - 1; i >= 0; --i) {
            k %= size;
            if (k == 0 && isalpha(s[i])) {
                res += s[i];
                break;
            }
            if (isdigit(s[i])) size /= s[i] - '0';
            else --size;
        }
        return res;
    }
};