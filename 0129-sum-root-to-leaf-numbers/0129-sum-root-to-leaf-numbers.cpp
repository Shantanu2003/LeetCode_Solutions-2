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
private:
int sumNum(TreeNode* root,int sum){
    int sum2=0;
         if(root == NULL){
             return 0; 
         }
         sum = sum*10 + root->val;
        
        if (root->left == NULL && root->right == NULL) {
                return sum; // Return the current path sum for leaf nodes
        }         
         sum2 += sumNum(root->left,sum);
         sum2 += sumNum(root->right,sum);

         return sum2;
}
public:
    int sumNumbers(TreeNode* root) {
         return sumNum(root,0);
    }
};