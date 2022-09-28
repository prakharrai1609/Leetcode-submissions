# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        N = 0
        temp = ListNode()
        temp = head
        while temp :
            temp = temp.next
            N += 1
            
        if N == n : return head.next
        
        front = 1
        temp = head
        while temp and (n + front != N) :
            temp = temp.next
            front += 1
            
        last = ListNode()
        if temp.next.next :
            last = temp.next.next
        else :
            last = None
        temp.next = last
        return head