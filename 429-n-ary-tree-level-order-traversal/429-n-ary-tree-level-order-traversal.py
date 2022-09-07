"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root : 
            return []
        
        ans, queue = [], [root]
        
        while queue :
            row = []
            N = len(queue)
            
            for _ in range(N) :
                t = queue.pop(0)

                for node in t.children :
                    queue.append(node)
                row.append(t.val)
            ans.append(row)
        
        return ans