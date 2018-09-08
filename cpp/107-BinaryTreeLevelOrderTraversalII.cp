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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q1;
        vector<vector<int>> result;
        stack<vector<int>> sresult;
        if (root == nullptr)
            return result;
        
        q1.push(root);
        while (!q1.empty()) {
        queue<TreeNode*> q2;
            vector<int> r;
            while (!q1.empty()) {
                TreeNode* tmp = q1.front();
                if (tmp->left)
                    q2.push(tmp->left);
                if (tmp->right)
                    q2.push(tmp->right);
                q1.pop();
                r.push_back(tmp->val);
            }
            sresult.push(r);
            q1 = q2;
        }
        while (!sresult.empty()) {
            result.push_back(sresult.top());
            sresult.pop();
        }
        return result;
    }
};