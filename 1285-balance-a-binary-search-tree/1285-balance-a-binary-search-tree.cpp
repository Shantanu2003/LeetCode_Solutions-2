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
    void inorder(TreeNode* root, vector<int>& res){
        if(root == NULL)
        return;

        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    TreeNode* constructTree(vector<int>&res, int start, int end){
        if (start > end) {
        return NULL;
        }

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(res[mid]);

        node->left = constructTree(res, start, mid - 1);
        node->right = constructTree(res, mid + 1, end);

        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>res;

        inorder(root, res);
        

        return constructTree(res, 0, res.size() - 1);
    }
};