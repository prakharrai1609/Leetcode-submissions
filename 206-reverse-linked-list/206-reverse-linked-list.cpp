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
    ListNode* ans;
public:
    void revList(ListNode* head, ListNode* prev) {
        if (!head) {
            ans = prev;
            return;
        }
        ListNode* newHead = head->next;
        head->next = prev;
        revList(newHead, head);
    }
    
    ListNode* reverseList(ListNode* head) {
        revList(head, nullptr);
        return ans;
    }
};