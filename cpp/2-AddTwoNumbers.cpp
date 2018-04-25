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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        int up = 0;
        ListNode *result = nullptr, *currentr, *current1 = l1, *current2 = l2;
        while (current1 || current2) {
            int a = (current1 == nullptr ? 0 : current1->val);
            int b = (current2 == nullptr ? 0 : current2->val);
            int tmp = a + b; 
            if (current1) {
                current1->val = (tmp + up) % 10;
            }
            else {
                current2->val = (tmp + up) % 10;
            }
            up = (tmp + up) / 10; 
            if (result == nullptr) {
                result = current1;
                currentr = result;
            } else {
                if (current1) {
                    currentr->next = current1;
                }
                else if (current2) {
                    currentr->next = current2;
                }
                currentr = currentr->next;
            }
            if (current1)
                current1 = current1->next;
            if (current2)
                current2 = current2->next;
        }
        if (up != 0) {
            ListNode *l = new ListNode(up);
            currentr->next = l;
        }
        return result;
    }
};
