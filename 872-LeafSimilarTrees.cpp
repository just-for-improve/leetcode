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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);
        if (leaf1 == leaf2)
            return true;
        return false;
    }
    void getLeaf(TreeNode* root, vector<int>& result) {
        if (root) {
            if (root->left == nullptr && root->right == nullptr) {
                result.push_back(root->val);
            }
            getLeaf(root->left, result);
            getLeaf(root->right, result);
        }
    }
};