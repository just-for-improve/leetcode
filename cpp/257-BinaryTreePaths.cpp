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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> r;
        string p = "" ;
        findPath(root, r, p);
        return r;
    }
    void findPath(TreeNode* root, vector<string>& r, string p) {
        if (root) {
            if (p == "") p = to_string(root->val);
            else p += "->" + to_string(root->val);
            if (root->right == nullptr && root->left == nullptr) {
                r.push_back(p);
            }
            findPath(root->left, r, p);
            findPath(root->right, r, p);
        }
    }
};