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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;

        root = solve(root, to_delete, forest);

        if (root != nullptr) {
            forest.push_back(root);
        }

        return forest;
    }
    TreeNode* solve(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& forest) {
        if (root == nullptr) {
            return nullptr;
        }

        root->left = solve(root->left, to_delete, forest);
        root->right = solve(root->right, to_delete, forest);

        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if (root->left != nullptr) {
                forest.push_back(root->left);
            }
            if (root->right != nullptr) {
                forest.push_back(root->right);
            }
            delete root;
            return nullptr;
        }

        return root;
    }
};