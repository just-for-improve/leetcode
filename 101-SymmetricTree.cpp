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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSame(root->left, root->right);
    }
    bool isSame(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        else if (t1 == nullptr || t2 == nullptr) {
            return false;
        } else if (t1->val == t2->val) {
            return isSame(t1->left, t2->right) && isSame(t1->right, t2->left);
        } else {
            return false;
        }
    }
};