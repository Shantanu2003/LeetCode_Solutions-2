class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_count = 1;
        for(int i = 0 ; i<points.size(); i++){
            int n =0;
            unordered_map<double,int>mp;
            for(int j = 0 ;j<points.size() ; j++){

                if( i==j){
                    continue;
                }
                if((points[j][0]- points[i][0])==0){
                    n++;
                    continue;
                }
                double m = (double)(points[j][1]- points[i][1])/(double)(points[j][0]- points[i][0]);
                mp[m]++;
            }
        for (auto i : mp) {
            if (max_count < i.second+1) {
                max_count = i.second+1;
            }
        }
        max_count = max(max_count,n+1);
        }
        
        return max_count;
    }
};