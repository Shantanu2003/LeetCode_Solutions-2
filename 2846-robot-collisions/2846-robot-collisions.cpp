// class Solution {
// public:
//     vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
//         int n = positions.size();
//         map<int,int>mp;
//         for(int i = 0 ; i < n ; i++){
//             mp[i] = healths[i];
//         }
//         deque<int>right;
//         deque<int>left;

//         for(int  i = 0 ; i < n ; i++){
//             if(directions[i] == 'R')
//             right.push_back(i);

//             else
//             left.push_back(i);
//         }        

//         while(!right.empty() && !left.empty()){
//             int top1 = right.front();
//             int top2= left.front();
    
//         if(positions[top1] < positions[top2]){
//             int health = mp[top1];
//             right.pop_front();

//             int health2 = mp[top2];
//             left.pop_front();


//             if(health2 > health){
//                 left.push_front(top2);
//                 mp[top2] = health2-1;
//                 mp.erase(top1);
//                 //yaha pe neeche jaa raha hai hume upar push krna hai
//             }
//             else if(health2 < health){
//                 right.push_front(top1);
//                 mp[top1] = health-1;
//                 mp.erase(top2);

//             }
//             else{
//                mp.erase(top1);
//                mp.erase(top2);
//             }
//         }
//         else{
//             break;
//         }
//         }

//         vector<int>survived;
//         for(auto i :mp)
//         survived.push_back(i.second);


//         return survived;

//     }
// };

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // Sort indices based on positions
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> stk; // stack to hold the indices of robots moving to the right
        vector<int> survived_health(n, -1); // -1 means the robot did not survive

        for (int i = 0; i < n; ++i) {
            int id = idx[i];
            if (directions[id] == 'R') {
                stk.push(id);
            } else {
                while (!stk.empty() && healths[stk.top()] < healths[id]) {
                    int top_id = stk.top();
                    stk.pop();
                    healths[id] -= 1;
                }
                if (!stk.empty() && healths[stk.top()] == healths[id]) {
                    stk.pop(); // both robots are destroyed
                } else if (!stk.empty() && healths[stk.top()] > healths[id]) {
                    healths[stk.top()] -= 1; // top robot health decreases by 1
                } else {
                    survived_health[id] = healths[id]; // no more collisions, robot survives
                }
            }
        }

        // Remaining robots in the stack survive
        while (!stk.empty()) {
            survived_health[stk.top()] = healths[stk.top()];
            stk.pop();
        }

        // Collect surviving robots' healths in the original order
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (survived_health[i] != -1) {
                result.push_back(survived_health[i]);
            }
        }

        return result;
    }
};
