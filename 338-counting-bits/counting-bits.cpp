class Solution {
public:
    vector <int> countBits(int num) {
        vector<int> ans(num+1);
        int x = 0;
        int b = 1;
        while(b<=num){
            while(x<b && x+b <=num){
                ans[x+b] = ans[x] +1;
                ++x;
            }
            x= 0;
            b<<= 1;
        }
        return ans;
    }
};

