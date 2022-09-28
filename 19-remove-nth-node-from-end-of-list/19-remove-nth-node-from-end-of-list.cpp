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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            len++;
        }
        
        if (len == n)
            return head->next;
        
        int front = 1;
        temp = head;
        while (temp and (len - front != n)) {
            temp = temp->next;
            front++;
        }
        
        ListNode* last = nullptr;
        if (temp->next->next)
            last = temp->next->next;
        
        temp->next = last;
        return head;
    }
};