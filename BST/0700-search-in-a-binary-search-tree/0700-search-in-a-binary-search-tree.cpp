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
    TreeNode* searchBST(TreeNode* root, int val) {
        //TC:O(log n) 
        //SC:O(1)
        //Intuition: Use the BST property to eliminate half of the search space at each step. Compare the target with the current node and move left or right accordingly until the value is found or the tree ends.
        while(root != NULL && root -> val != val){
            root = val < root -> val ? root -> left : root -> right;
        }
        return root;
    }
};