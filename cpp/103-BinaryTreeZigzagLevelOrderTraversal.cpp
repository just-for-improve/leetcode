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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return vector<vector<int>>();
        stack<int> s;
        queue<TreeNode*> q1, q2;
        vector<vector<int>> result;
        q1.push(root);
        bool mark = true;
        while (!q1.empty()) {
            vector<int> tmp;
            while (!q1.empty()) {
                if (mark)
                    tmp.push_back(q1.front()->val);
                else
                    s.push(q1.front()->val);
                if (q1.front()->left) {
                    q2.push(q1.front()->left);
                }
                if (q1.front()->right) {
                    q2.push(q1.front()->right);
                }
                q1.pop();
            }
            if (!mark) {
                while (!s.empty()) {
                    tmp.push_back(s.top());
                    s.pop();
                }
            }
            mark = !mark;
            result.push_back(tmp);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        return result;
    }
};