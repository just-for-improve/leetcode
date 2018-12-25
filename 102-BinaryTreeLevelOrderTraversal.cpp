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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        vector<vector<int>> result;
        if (!root)
            return result;
        q1.push(root);
        while (!q1.empty()) {
            vector<int> tmp;
            while (!q1.empty()) {
                tmp.push_back(q1.front()->val);
                if (q1.front()->left)
                    q2.push(q1.front()->left);
                if (q1.front()->right)
                    q2.push(q1.front()->right);
                q1.pop();
            }
            result.push_back(tmp);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        return result;
    }
};