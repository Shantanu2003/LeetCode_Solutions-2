class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st;
        stack<int> st1;
        string s1="";
        string t1 ="";
        for(int i = 0 ; i < s.size(); i++){
                if(s[i]=='#' && !st.empty()){
                    st.pop();
                }
                else if(s[i] != '#'){
                    st.push(s[i]);
                }
        }
        for(int i = 0 ; i < t.size(); i++){
                if(t[i]=='#' && !st1.empty()){
                    st1.pop();
                }
                else if(t[i] != '#'){
                    st1.push(t[i]);
                }
        }
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        while(!st1.empty()){
            t1+=st1.top();
            st1.pop();
        }
    reverse(s1.begin(),s1.end());
    reverse(t1.begin(),t1.end());

    if(s1==t1)
    return true;

    return false;
    }
};