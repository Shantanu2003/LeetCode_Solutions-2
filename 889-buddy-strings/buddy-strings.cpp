#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int len = s.size();
        vector<int> ans(26,0);
        if(len != goal.size()){
            return false;
        }

        if(s == goal){
        for(auto& i : s){
        ans[i - 'a'] += 1;
        if(ans[i - 'a'] ==2){
            return true;
        }
        }
        return false;
        }
            int firstIndex = -1;
            int secondIndex = -1;
            for(int  i = 0 ; i <len  ; ++i){
                if(s[i] != goal[i]){
                    if(firstIndex == -1){
                        firstIndex = i;
                    }
                    else if(secondIndex == -1){
                        secondIndex = i;
                    }
                    else{
                        return false;
                    }
                }
            }
            if(secondIndex == -1){
                return false;
            }
            return s[firstIndex] == goal[secondIndex] &&
            s[secondIndex] == goal[firstIndex];  
    }
};