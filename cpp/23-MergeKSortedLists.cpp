/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Cmp {
    bool operator()(const ListNode* node1, const ListNode* node2) {
        return node1->val > node2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> q;
        for (auto list : lists) {
            ListNode* node = list;
            while (node) {
                q.push(node);
                node = node->next;
            }
        }
        bool start = true;
        ListNode* result = nullptr, *current = nullptr;
        if (q.empty()) return result;
        
        while (!q.empty()) {
            if (start) {
                start = false;
                result = q.top();
                current = q.top();
            } else {
                current->next = q.top(); 
                current = current->next;
            }
            q.pop();
        }
        current->next = nullptr;
        return result;
    }
};