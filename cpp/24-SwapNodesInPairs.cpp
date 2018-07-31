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
    ListNode* swapPairs(ListNode* head) {
        
        if (!head) return nullptr;
        
        int counter = 0;
        ListNode* tmp = nullptr, *current = head, *result = nullptr, *lastbp = nullptr;
        
        while (current) {
            counter += 1;
            if (counter % 2 == 1) {
                tmp = current;
                current = current->next;
            } else {
               if (!lastbp) {
                   result = current;
                   tmp->next = current->next;
                   result->next = tmp;
               } else {
                   lastbp->next = current;
                   tmp->next = current->next;
                   lastbp->next->next = tmp;
               }
               lastbp = tmp;
               current = tmp->next;
            }
        }
        
        if (!result)
            return head;
        return result;
    }
};