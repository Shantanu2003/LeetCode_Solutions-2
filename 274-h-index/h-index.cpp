class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int store = 0;
        //vector<int> visited(n);
        for(int i = 0 ; i < citations.size() ; i++){
           if(citations[i] >= n-i){ 
           store = n-i;
           break;
    }
    }
    return store; 
    }
};