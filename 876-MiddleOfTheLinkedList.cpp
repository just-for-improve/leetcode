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
    ListNode* middleNode(ListNode* head) {
        int len = 0, mid;
        ListNode *current = head;
        while (current) {
            ++len;
            current = current->next;
        }
        mid = len / 2;
        current = head;
        while (mid > 0) {
            current = current->next;
            --mid;
        }
        return current;
    }
};