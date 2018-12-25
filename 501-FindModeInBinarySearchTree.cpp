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
    int last = 0;
    int max_count = -1;
    int count = 0;
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        do_find_mode(root, result);
        return result;
    }
    void do_find_mode(TreeNode* root, vector<int>& result) {
        if (root) {
            do_find_mode(root->left, result);
            if (max_count == -1) {
                result.push_back(root->val);
                last = root->val;
                count = 1;
                max_count = 1;
            } else {
                count = root->val == last? count + 1 : 1;
                if (count == max_count)  {
                    result.push_back(root->val);
                } else if (count > max_count) {
                    result.clear();
                    result.push_back(root->val);
                    max_count = count;
                }
                last = root->val;
            }
            do_find_mode(root->right, result);
        }
    }
};