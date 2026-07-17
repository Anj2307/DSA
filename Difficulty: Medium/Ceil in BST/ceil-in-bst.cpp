/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil = -1; 
        
        while (root != nullptr) {
            // Exact match found, return immediately
            if (root->data == x) {
                return root->data;
            }
            
            // Current data is smaller, look for larger values in the right subtree
            if (x > root->data) {
                root = root->right;
            } 
            // Current data is larger, save it as a potential ceiling and check left for a closer one
            else {
                ceil = root->data;
                root = root->left;
            }
        }
        
        return ceil;
    }
};
