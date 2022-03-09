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
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return nullptr;
        
        ListNode * slow, *fast, *entry;
        slow = fast = entry = head;
        
        while (fast->next and fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        
        return nullptr;
    }
};