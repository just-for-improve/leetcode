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
private:
    int max_depth = 0;
public:
    int maxDepth(Node* root) {
        getMaxDepth(root, 1);
        return max_depth;
    }
    void getMaxDepth(Node* root, int depth) {
        if (root) {
            if (depth > max_depth) 
                max_depth = depth;
            for (auto child: root->children) {
                getMaxDepth(child, depth + 1);
            }
        }
    }
};