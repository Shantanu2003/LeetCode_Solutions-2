class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>st;
        for(string s: logs){
            if(s == "../"){
                if(st.size() > 0)
                st.pop();
            }            
            else if(s == "./")
            continue;

            else
            st.push(1);
        }



        return st.size();
    }
};