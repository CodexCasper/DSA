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
int ans , count = 0;
void inorder(TreeNode* root , int k){
    // Intuition:
// Since the inorder traversal of a BST visits nodes in sorted order,
// traverse the tree in inorder and count the visited nodes.
// As soon as the count becomes k, return that node's value.
// This avoids storing all the node values.
    if(root == NULL)
        return;

    inorder(root -> left ,k);

    count++;

    if(count == k){
        ans = root -> val;
        return;
    }
    inorder(root->right,k);    
}
    int kthSmallest(TreeNode* root, int k) {
        //TC:O(n) , SC:O(h)
        inorder(root , k);
        return ans;
    }
};