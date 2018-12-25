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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int length = 0;
        ListNode* current = head, *tmp = nullptr;
        while (current) {
            ++length;
            current = current->next;
        }
        if (k >= length) {
            k = k % length;
        }
        if (k == 0)
            return head;
        int location = length - k - 1;
        current = head;
        while (location > 0) {
            current = current->next;
            --location;
        }
        tmp = current->next;
        current->next = nullptr;
        current = tmp;
        while (current->next) {
            current = current->next;
        }
        current->next = head;
        return tmp;
    }
};