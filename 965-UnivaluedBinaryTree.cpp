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
private:
    bool start = false;
    int last;
public:
    bool isUnivalTree(TreeNode* root) {
        if (root) {
            if (!start) {
                start = true;
                last = root->val;
            } else if (root->val != last) {
                return false;
            }
            return isUnivalTree(root->left) && isUnivalTree(root->right);
            
        }
        return true;
    }
};