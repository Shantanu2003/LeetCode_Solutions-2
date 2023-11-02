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
vector<int> inorderNodes;
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);
        // Store the nodes in the list.
        inorderNodes.push_back(root->val);
        inorderTraversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorderTraversal(root);

        //sort(inorderNodes.begin(), inorderNodes.end());
        //int n = inorderNodes.size();
       // long long mindiff = inorderNodes[n-2] - inorderNodes[n-1];
        int min1 = INT_MAX;
        int diff;
        for(int i = 1 ; i < inorderNodes.size(); i++){
            diff = 0; 
            int diff = abs(inorderNodes[i]-inorderNodes[i-1]);
            min1 = min(min1,diff);
            } 
        return min1;
    }
};