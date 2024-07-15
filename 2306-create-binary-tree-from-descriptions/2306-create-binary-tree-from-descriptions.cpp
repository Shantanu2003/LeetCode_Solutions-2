/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,unordered_map<int,int>>mp;
        unordered_set<int>s;
        for(auto it: descriptions){
            mp[it[0]][it[1]] = it[2]; 
            s.insert(it[1]);
        }
        vector<int>order;
        queue<TreeNode*>q;
        TreeNode* root = nullptr;
        for(auto i : mp){
            if(s.find(i.first) == s.end()){
                root= new TreeNode(i.first);
                q.push(root);
                break;
            }
        }

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();


            if(mp.find(top->val) != mp.end()){
            unordered_map<int,int>child = mp[top->val];
            for(auto i : child){
                if(i.second == 1){
                    top->left = new TreeNode(i.first);
                    q.push(top->left);
                }
                else{
                    top->right = new TreeNode(i.first);
                    q.push(top->right);
                }
            }
            }
        }
    return root;
    }
};