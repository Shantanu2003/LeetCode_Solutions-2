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
TreeNode* dfs(TreeNode* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->val == value) {
        return root;
    }

    TreeNode* leftResult = dfs(root->left, value);
    if (leftResult != nullptr) {
        return leftResult;
    }

    return dfs(root->right, value);
}

TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || root== p || root == q){
        return root;
    }

    TreeNode* left = helper(root->left, p,q);
    TreeNode* right = helper(root->right, p, q);

    if(left != NULL && right!= NULL){
        return root;
    }
    else if(!left){
        return right;
    }
    else{
        return left;
    }
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        if(root == NULL)
        return " ";

        TreeNode* start = dfs(root, startValue);
        TreeNode* dest = dfs(root, destValue);

        TreeNode* lca = helper(root,start,dest);

        string res1;
        solve2(lca,start,res1);
        string res2;
        solve2(lca,dest,res2);
        for (char& c : res1) {
            c = 'U';
        }
        return res1+res2;
    }

    bool solve2(TreeNode* root, TreeNode* target, string& path) {
        if (root == nullptr) {
            return false;
        }

        if (root == target) {
            return true;
        }

        path.push_back('L');
        if (solve2(root->left, target, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (solve2(root->right, target, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }


};