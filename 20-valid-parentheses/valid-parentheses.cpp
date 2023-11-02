class Solution {
public:
    bool isValid(string s) {
            stack<char> st;
            bool flag =true;

            for(int i =0; i<s.size(); i++){
   
                if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                    st.push(s[i]);
                }
                else{

                    if(st.empty())
                    flag= false;

                   else if(st.top()== '(' && s[i] != ')') 
                   flag= false;

                   else if (st.top()== '{' && s[i] != '}')
                   flag= false;

                   else if(st.top()== '[' && s[i] != ']')
                   flag= false;

                   else
                   st.pop();
                }

            }
            
    if(!st.empty()){
    flag = false;
    }
    return flag;
    }
};