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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return judge(root, depth);
    }
    bool judge(TreeNode* root, int& depth) {
        if (root == nullptr) {
            depth = 0;
            return true;
        }
        int l = 0, r = 0;
        bool y1 = judge(root->left, l);
        if (!y1)
            return false;
        bool y2 = judge(root->right, r);
        if (!y2)
            return false;
        depth = max(l, r) + 1;
        if (abs(l - r) <= 1)
            return true;
        else
            return false;
    }
};