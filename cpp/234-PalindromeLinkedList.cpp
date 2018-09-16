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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int len = 0, i = 0;
        ListNode *current = head;
        while (current) {
            ++len;
            current = current->next;
        }
        current = head;
        while (i < len / 2) {
            s.push(current->val);
            current = current->next;
            ++i;
        }
        if (len % 2 == 1)
            current = current->next;
        while (current) {
            if (current->val != s.top())
                return false;
            current = current->next;
            s.pop();
        }
        return true;
    }
};