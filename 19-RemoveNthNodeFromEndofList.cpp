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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pointer1 = head, *pointer2 = head;
        for (int i = 0; i < n && pointer2; ++i) {
            pointer2 = pointer2->next;
        }
        while (pointer2 && pointer2->next) {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }
        if (!pointer2)
            head = pointer1->next;
        else
            pointer1->next = pointer1->next->next;
        return head;
    }
};
