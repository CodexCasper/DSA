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
bool isvalid(TreeNode* root , long long low , long long high){
    // Intuition:
// A valid BST requires every node to lie within a valid range.
// Initially, the range is (-∞, +∞).
// For the left subtree, the upper bound becomes the current node's value.
// For the right subtree, the lower bound becomes the current node's value.
// If any node violates its range, the tree is not a BST.
    if(root == NULL){
        return true;
    } 

    if(root->val <= low || root->val >= high)
    return false;

    return isvalid(root->left , low , root->val) &&
         isvalid(root->right , root->val , high);
}
    bool isValidBST(TreeNode* root) {
        //TC:O(n) every node visited once
        //SC:O(h) recursion stack , logn(balanced) , n(skewed)
        return isvalid(root , LLONG_MIN , LONG_MAX);
    }
};