/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(result, root);
        return result;
    }
    void inorder(vector<int> &result, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorder(result, root->left);
        result.push_back(root->val);
        inorder(result, root->right);
    }
};