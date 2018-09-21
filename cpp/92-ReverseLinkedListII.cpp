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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // init
        ListNode* tmpHead = new ListNode(-1);
        tmpHead->next = head;
        ListNode* tmp = nullptr, *current = tmpHead, *currentp;
        int distance = n - m;
        while (current && --m > 0) {
            current = current->next;
        }
        currentp = current->next;
        while (currentp && distance-- > 0) {
            tmp = currentp->next;
            currentp->next = tmp->next;
            tmp->next = current->next;
            current->next = tmp;
        }
        // end
        head = tmpHead->next;
        delete tmpHead;
        return head;
    }
}