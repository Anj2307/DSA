from collections import deque

class Solution:
    def zigzagLevelOrder(self, root: TreeNode | None) -> list[list[int]]:
        # Fix 1: Handle empty tree edge case
        if not root:
            return []
            
        # Fix 2: Wrap the tuple in a list [] so it initializes correctly
        q = deque([(root, 0)])
        l = list()
        
        while q:
            r, col = q.popleft()
            
            if len(l) < col + 1:
                l.append([r.val])
            else:
                # Fix 3: Alternate direction based on the level index (col)
                if col % 2 == 1:
                    l[col].insert(0, r.val)  # Insert at front for Right-to-Left
                else:
                    l[col].append(r.val)     # Append to back for Left-to-Right
            
            if r.left:
                q.append((r.left, col + 1))
            if r.right:
                q.append((r.right, col + 1))
                
        return l
