class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int j,k;
        j=numbers.size()-1;
        k=0;
        for(int i =0 ; i<numbers.size() ; i++){
           
                if(numbers[k]+ numbers[j] == target){
                    ans[0] = (k+1);
                    ans[1] =(j+1);
                    //break;
                }
                else if(numbers[k]+ numbers[j] < target ){
                    k++;
                }
                else{
                    j--;
                }
        }
        return ans;
    }
};