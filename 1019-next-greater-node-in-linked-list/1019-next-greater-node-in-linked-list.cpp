/*
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> a;
        ListNode *temp = head;
        while (temp) {
            a.push_back(temp->val);
            temp = temp->next;
        }
        
        int N = size(a);
        vector<int> ngl(N);
        stack<int> s;
        for (int i = N - 1; i >= 0; i--) {
            while (!s.empty() and s.top() <= a[i]) 
                s.pop();
            ngl[i] = s.empty() ? 0 : s.top();
            s.push(a[i]);
        }
        
        return ngl;
    }
};