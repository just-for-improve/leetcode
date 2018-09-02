/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == nullptr) {
            return head;
        }
        int index = 0;
        stack<ListNode*> s;
        ListNode *current = head, *result = nullptr, *current_result = nullptr, *tmp = nullptr, *lastbp = nullptr;
        while (current) {
            index++;
            tmp = current;
            current = current->next;
            if (index % k == 0) {
                if (!result) {
                    result = tmp;
                    current_result = result;
                } else {
                    s.push(tmp);
                }
                while (!s.empty()) {
                    ListNode* node = s.top();
                    current_result->next = node;
                    current_result = current_result->next;
                    s.pop();
                }
                lastbp = current;
            } else {
                s.push(tmp);
            }
        }
        if (!result) return head;
        current_result->next = lastbp;
        return result;
    }
};