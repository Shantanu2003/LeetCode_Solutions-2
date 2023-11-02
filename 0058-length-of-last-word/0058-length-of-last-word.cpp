class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0) return 0;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }

        result = stack.top();
        return result.size();
    }
};