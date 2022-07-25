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

/* approach 1

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

*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next) {
            return head;
        }
        
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};