class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i = 0 ; i < tokens.size() ; i++){
           if(tokens[i]!= "+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
               st.push(tokens[i]);
           }
           else{
              int top1 =0, top2 = 0,res;
              top1 = stoi(st.top());
              st.pop();
              top2 = stoi(st.top());
              st.pop();
              string oper  = (tokens[i]);
              
              if(oper == "+"){
              res= top2 + top1;
              st.push(to_string(res));
              }

              else if(oper == "-"){
              res= top2 - top1;
              st.push(to_string(res));
              }

              else if(oper == "*"){
              res= top2 * top1;
              st.push(to_string(res));
              }

              else{
              res= top2 / top1;
              st.push(to_string(res));
              }
           }
        }
        return stoi(st.top());
    }
};