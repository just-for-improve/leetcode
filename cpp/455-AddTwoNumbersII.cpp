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
        int len1 = 0, len2 = 0;
        stack<ListNode*> s1, s2;
        ListNode *current1 = l1, *current2 = l2;
        while (current1) {
            ++len1;
            s1.push(current1);
            current1 = current1->next;
        }
        while (current2) {
            ++len2;
            s2.push(current2);
            current2 = current2->next;
        }
        if (len1 < len2) {
            swap(s1, s2);
            swap(l1, l2);
        }
        int up = 0, tmp;
        while (!s1.empty() && !s2.empty()) {
            tmp = s1.top()->val + s2.top()->val + up;
            s1.top()->val = tmp % 10;
            up = tmp / 10;
            s1.pop();
            s2.pop();
        }
        while (!s1.empty()) {
            if (up > 0) {
                tmp = s1.top()->val + up;
                s1.top()->val = tmp % 10;
                up = tmp / 10;
            } else {
                return l1;
            }
            s1.pop();
        }
        if (up > 0) {
            l2->val = up;
            l2->next = l1;
            return l2;
        }
        return l1;
    }
};