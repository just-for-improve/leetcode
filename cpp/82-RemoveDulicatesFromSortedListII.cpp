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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* result = nullptr, *current = head;
        int pass = 0;
        // head
        while (head && head->next && head->val == head->next->val) {
            pass = head->val;
            while (head && head->val == pass) {
                head = head->next;
            }
        }
        // others
        current = head;
        while (current && current->next) {
            if (current->next->next && current->next->val == current->next->next->val) {
                pass = current->next->val;
                ListNode* tmp = current->next;
                while (tmp && tmp->val == pass) {
                    tmp = tmp->next;
                }
                current->next = tmp;
            } else
                current = current->next;
        }
        return head;
    }
};