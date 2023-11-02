class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];
        while(i < intervals.size() && intervals[i][1] < start){
            ans.push_back(intervals[i]);
            i++;
        }  
        while(i < intervals.size() && end >= intervals[i][0]){
            start = newInterval[0];
            end = newInterval[1];
            newInterval[0] = min(start, intervals[i][0]);
            newInterval[1] = max(end, intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};