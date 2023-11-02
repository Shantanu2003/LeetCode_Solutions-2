class Solution {
public:
    bool isPowerOfFour(int n) {
        int ans =0;
        for(int i=0; i <= 15; i++){
            ans= pow(4,i);
            if (ans == n){
                return true;
            }
        }
              return false;
    }
};