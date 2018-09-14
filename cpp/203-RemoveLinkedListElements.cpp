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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return head;
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode* current = head;
        while (current && current->next) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};