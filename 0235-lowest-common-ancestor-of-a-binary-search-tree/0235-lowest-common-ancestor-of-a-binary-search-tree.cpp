/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         // Intuition:
// Use the BST property.
// - If both p and q are smaller than the current node, go left.
// - If both are larger than the current node, go right.
// - Otherwise, the current node is the Lowest Common Ancestor.
         //TC:O(h) , SC:O(1)
         while(root != NULL){
            if(p->val < root->val && q->val < root->val)
                root = root -> left;
            else if(p -> val > root -> val && q->val > root->val)
                root = root -> right;
            else return root;    
         }
         return NULL;  
    }
};