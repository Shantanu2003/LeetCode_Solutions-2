
class Solution {
public:
    long long int mySqrt(int x) {
        long long int start = 0, end = x;
        long long int mid = start + (end-start)/2;
        long long int a = -1;
        while(start<=end){
        long long int ans = mid*mid;
        if (ans==x){
            return mid;
        }
        else if(ans<x){
            a= mid;
            start = mid +1;
            }
        else{
            end = mid -1;
        }
        mid = start + (end-start)/2;
        }
 return a;
    }
     long long int bst ( int n){
        return bst(n);
    }
};