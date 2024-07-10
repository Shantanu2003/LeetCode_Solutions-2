class Solution {
public:
    int minOperations(vector<string>& logs) {
        int j = 0;;
        for(string s: logs){
            if(s == "../"){
                if(j > 0)
                j--;
            }            
            else if(s == "./")
            continue;

            else
            j++;
        }



        return j;
    }
};