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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (l != 0 && r != 0)
            return min(l, r) + 1;
        else {
            return max(l, r) + 1;
        }
    }
};