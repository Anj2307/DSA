# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode | None) -> list[int]:
        if root is None:
            return []
        q=deque()
        q.append((root,0))
        l=list()
        while q:
            r,c=q.popleft()
            if len(l)<c+1:
                l.append(r.val)
            else:
                l[c]=r.val
            if r.left:
                q.append((r.left,c+1))
            if r.right:
                q.append((r.right,c+1))
        return l