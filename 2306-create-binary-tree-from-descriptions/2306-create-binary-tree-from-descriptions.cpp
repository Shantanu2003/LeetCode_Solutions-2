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
    TreeNode* insertLevelOrder(const vector<string>& arr, int i) {
        TreeNode* root = nullptr;
        if (i < arr.size() && arr[i] != "null") {
            root = new TreeNode(stoi(arr[i]));
            root->left = insertLevelOrder(arr, 2 * i + 1);
            root->right = insertLevelOrder(arr, 2 * i + 2);
        }
        return root;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, int> leftChild;
        unordered_map<int, int> rightChild;
        unordered_set<int> children;

        for (const auto& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (nodes.find(parent) == nodes.end())
                nodes[parent] = new TreeNode(parent);
            if (nodes.find(child) == nodes.end())
                nodes[child] = new TreeNode(child);

            if (isLeft)
                leftChild[parent] = child;
            else
                rightChild[parent] = child;

            children.insert(child);
        }

        // Find the root
        int rootVal = -1;
        for (const auto& [key, _] : nodes) {
            if (children.find(key) == children.end()) {
                rootVal = key;
                break;
            }
        }

        TreeNode* root = nodes[rootVal];
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (leftChild.find(node->val) != leftChild.end()) {
                node->left = nodes[leftChild[node->val]];
                q.push(node->left);
            }
            if (rightChild.find(node->val) != rightChild.end()) {
                node->right = nodes[rightChild[node->val]];
                q.push(node->right);
            }
        }

        return root;
    }
};
