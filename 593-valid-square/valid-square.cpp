class Solution {
public:
    int helper(vector<int> &A,vector<int> &B){
        return (pow(A[0]-B[0],2)+pow(A[1]-B[1],2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a=helper(p1,p2);
        int b=helper(p1,p3);
        int c=helper(p1,p4);
        int d=helper(p2,p3);
        int e=helper(p2,p4);
        int f=helper(p3,p4);
        vector<int> v={a,b,c,d,e,f};
        unordered_map<int,int> mp;
        for(auto i:v)mp[i]++;

        if(mp.size()!=2)return 0;
        for(auto i:mp){
            if(i.first==0)return 0;
            return i.second==4 || i.second==2;
        }
        return 0;
    }
};