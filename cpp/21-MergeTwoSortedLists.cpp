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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        ListNode *result, *current, *p, *tmp;
        if (l1->val < l2->val) {
            result = l1;
            p = l2;
        } else {
            result = l2;
            p = l1;
        }
        current = result;
        while (p) {
            if (current->next && current->next->val < p->val) {
                current = current->next;
            } else {
                tmp = p;
                p = p->next;
                tmp->next = current->next;
                current->next = tmp;
                current = current->next;
            } 
        }
        return result;
    }
};