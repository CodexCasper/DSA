/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* build(vector<int>& preorder, int &i , int bound){
    if(i == preorder.size() || preorder[i] > bound)
            return NULL;

    TreeNode* root = new TreeNode(preorder[i++]);
    root -> left = build(preorder , i , root -> val);
    root -> right = build(preorder , i , bound);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //TC:O(n) , SC:O(h) recursion stack
        // Intuition:
// Use preorder traversal and an upper bound.
// Create nodes only if the current value is within the allowed bound.
// For the left subtree, the new bound is the current node's value.
// For the right subtree, reuse the parent's bound.
        int i = 0;
        return build(preorder , i , INT_MAX);
    }
};