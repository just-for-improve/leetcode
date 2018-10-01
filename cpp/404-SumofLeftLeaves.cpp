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
    int sumOfLeftLeaves(TreeNode* root) {
        return getSum(root, false);
    }
    int getSum(TreeNode* root, bool left) {
        if (root == nullptr)
            return 0;
        if (left && root->left == nullptr && root->right == nullptr)
            return root->val;
        int a = getSum(root->left, true);
        int b = getSum(root->right, false);
        return a + b;
    }
};