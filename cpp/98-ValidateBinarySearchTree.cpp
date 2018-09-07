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
    bool isValidBST(TreeNode* root) {
        int last = 0;
        bool start = true;
        return check(root, last, start);
    }
    bool check(TreeNode* root, int &last, bool& start) {
        if (root == nullptr)
            return true;
        bool a = check(root->left, last, start);
        if (start) {
            start = false;
            last = root->val;
        } else {
            if (root->val <= last) {
                return false;
            }
            last = root->val;
        }
        bool b = check(root->right, last, start);
        return a && b;
    }
};