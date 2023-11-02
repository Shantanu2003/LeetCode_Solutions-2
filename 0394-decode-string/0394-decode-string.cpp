class Solution {
public:
    string decodeString(string s) {
    stack<int> counts;
    stack<string> strings;
    string repeatedStr;
    std::string currentStr = "";
    int currentCount = 0;

    for (char c : s) {
        if (std::isdigit(c)) {
            currentCount = currentCount * 10 + (c - '0');
        } else if (c == '[') {
            counts.push(currentCount);
            strings.push(currentStr);
            currentCount = 0;
            currentStr = "";
        } else if (c == ']') {
            int repeatCount = counts.top();
            counts.pop();
            repeatedStr = currentStr;
            for (int i = 1; i < repeatCount; i++) {
                repeatedStr += currentStr;
            }
            currentStr = strings.top() + repeatedStr;
            strings.pop();
        } else {
            currentStr += c;
        }
    }

    return currentStr;
    }
};