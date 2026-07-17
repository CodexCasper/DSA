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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //TC:O(log n) = h , SC:O(1)
        // Intuition:
// Follow the BST property to find the correct NULL position and insert the new node there while maintaining the BST property.
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root;

        while(true){
            if(curr -> val <= val){

                if(curr -> right != NULL) 
                    curr = curr -> right;

                else{
                    curr -> right = new TreeNode(val);
                    break; 
                }
            } 

            else {

                if( curr -> left != NULL)
                    curr = curr -> left;

                else{
                    curr -> left = new TreeNode(val);
                    break;    
                } 
            }        
        }
        return root;
    }
};