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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return nullptr;
        ListNode* before_first_bigger_than_x = nullptr;
        ListNode *tmpHead = new ListNode(-1), *current = nullptr, *tmpNode = nullptr;
        tmpHead->next = head;
        current = tmpHead;
        while (current && current->next) {
            if (current->next->val >= x) {
                before_first_bigger_than_x = current;
                break;
            }
            current = current->next;
        }
        current = before_first_bigger_than_x;
        while (current && current->next) {
            if (current->next->val < x) {
                tmpNode = current->next;
                current->next = current->next->next;
                tmpNode->next = before_first_bigger_than_x->next;
                before_first_bigger_than_x->next = tmpNode;
                before_first_bigger_than_x = before_first_bigger_than_x->next;
            } else
                current = current->next;
        }
        head = tmpHead->next;
        delete tmpHead;
        return head;
    }
};