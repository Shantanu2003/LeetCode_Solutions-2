class Solution {
public:
    int convert(string s){
        int res= 0;

        for(int i = s.size() -1 ; i >= 0 ; i--){
            if(s[i] == '1')
            res += pow(2, (s.size()-i-1));
        }

        return res;
    }
    int findComplement(int num) {
         string res = "";
         while(num > 0){
            int a = num % 2;
            if(a == 1)
            res += '0';
            else
            res += '1';

            num /= 2;
         }  
         reverse(res.begin(), res.end());
         return convert(res);
         
    }
};


