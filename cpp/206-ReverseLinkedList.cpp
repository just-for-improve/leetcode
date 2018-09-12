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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head, * tmp = nullptr; 
        head = nullptr;
        while (current) {
            tmp = current;
            current = current->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};