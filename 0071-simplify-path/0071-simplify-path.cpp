class Solution {
public:
    string simplifyPath(string path) {
    stack<string> st;
    string res;
    for(int  i = 0 ; i < path.size() ;i++){
        if(path[i] == '/' ){
          continue;
        }
            string ans;
        while(i < path.size() && path[i] != '/')
            {
                ans += path[i];
                ++i;
            }
        if(ans == ".")
                continue;
        else if(ans == "..")
            {
                if(!st.empty())
                    st.pop();
            }
        else{
            st.push(ans);
        }
    }
    while(!st.empty()){
      res = "/" + st.top() + res;
      st.pop();
    }
    if(res.size() == 0)
    return "/";

    return res;
    }
};