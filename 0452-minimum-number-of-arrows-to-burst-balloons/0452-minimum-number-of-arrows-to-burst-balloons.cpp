#include <bits/stdc++.h>
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

        sort(points.begin(),points.end());

        int ans = 1;
        int start, end, first = points[0][1];
        for (int j = 0 ; j < points.size(); j++) {
            start = points[j][0];
            end = points[j][1];
           
            if (first < start) {
                ans++;
                first = end;
            }
            first = min(points[j][1],first);

        }
        return ans;
    }
};