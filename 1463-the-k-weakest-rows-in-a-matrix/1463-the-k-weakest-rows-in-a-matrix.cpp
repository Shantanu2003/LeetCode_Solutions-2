typedef pair<int, int> pi;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vector<int> ans;
        for(int i = 0 ; i < mat.size() ; i++){
            int index = 0;
            int value = 0 ;

            if(mat[i][mat[0].size()-1] == 1){
            index = i;  
            value = mat[0].size();
            }

            else if(mat[i][0] == 0){
            index = i; 
            value = 0;
            }
               
            else{
            for(int  j = 0 ; j< mat[0].size()-1; j++){
                index = i;
            
                if(mat[i][j] == 1 && mat[i][j+1] !=1){
                    value = j+1;
                    }
               }
            }  
            

            pq.push(make_pair(value,index));

               
        }
        for(int i = 0 ; i < k; i++){
           pair<int, int> top = pq.top();
           ans.push_back(top.second);
           pq.pop();
        }
        return ans;
    }
};