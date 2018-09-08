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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        createTree(root, nums, 0, nums.size() - 1);
        return root;
    }
    void createTree(TreeNode*& root, vector<int>& nums, int begin, int end) {
        if (begin > end) {
            root = nullptr;
            return;
        }
        int loc = (begin + end) / 2;
        root = new TreeNode(nums[loc]);
        createTree(root->left, nums, begin, loc - 1); 
        createTree(root->right, nums, loc + 1, end); 
    }
};