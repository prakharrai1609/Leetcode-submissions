/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kAhead, *first, *second;
        first = second = kAhead = head;
        
        for (int i = 0; i < k - 1; i++) {
            first = first->next;
            kAhead = kAhead->next;
        }
        
        while (kAhead->next) {
            kAhead = kAhead->next;
            second = second->next;
        }
        
        cout << first->val << ", " << second->val << endl;
        swap(first->val, second->val);
        return head;
    }
};