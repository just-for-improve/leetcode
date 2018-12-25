/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        int this_level = 1, next_level = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            for (int i = 0; i < this_level; ++i) {
                auto node = q.front();
                tmp.push_back(node->val);
                q.pop();
                for (auto child: node->children) {
                    if (child != nullptr) {
                        q.push(child);
                        ++next_level;
                    }
                }
            }
            this_level = next_level;
            next_level = 0;
            result.push_back(tmp);
        }
        return result;
    }
};