/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        p(root, result);
        return result;
    }
    void p(Node* root, vector<int> &result) {
        if (root) {
            result.push_back(root->val);
            for (auto node : root->children) {
                p(node, result);
            }
        }
    }
};