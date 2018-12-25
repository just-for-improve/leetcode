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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root)
            return result;
        double sum = 0;
        int this_level = 0, last_level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            sum = 0;
            for (int i = 0; i < last_level; ++i) {
                auto pointer = q.front();
                q.pop();
                sum += pointer->val;
                if (pointer->left) {
                    ++this_level;
                    q.push(pointer->left);
                }
                if (pointer->right) {
                    ++this_level;
                    q.push(pointer->right);
                }
            }
            result.push_back((double)sum / last_level);
            last_level = this_level;
            this_level = 0;
        }
        return result;
    }
};