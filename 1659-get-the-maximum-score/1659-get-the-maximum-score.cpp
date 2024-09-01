class Solution {
public:
    int maxSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        long long i = 0 , j = 0 , sum1 = 0, sum2 = 0, res = 0;
        while(i < n1 && j < n2){
            if(arr1[i] < arr2[j]){
                sum1 += arr1[i] % 1000000007;
                i++;
            }
            else if(arr2[j] < arr1[i]){
                sum2 += arr2[j] % 1000000007;
                j++;
            }
            else if(arr1[i] == arr2[j]){
                 res += (max(sum1,sum2) % 1000000007) + arr1[i];
                 i++;
                 j++;
                 sum1 = 0;
                 sum2 = 0;
            }
        }
        
        while(i < n1){
            sum1 += (arr1[i++] % 1000000007);
        }
        while(j < n2){
            sum2 += (arr2[j++] % 1000000007);
        }
        
        res += (max(sum1,sum2))% 1000000007;
        
        return res % 1000000007;
    }
};