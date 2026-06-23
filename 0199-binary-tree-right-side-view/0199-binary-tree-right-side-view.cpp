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
    void leftside(TreeNode* node , int level , vector<int> &ans){
        if(node == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(node -> val);
        }
        leftside(node -> left , level + 1 , ans);
        leftside(node -> right , level + 1 , ans);
    }
    void rightside(TreeNode* node , int level, vector<int> &ans){
        if(node == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(node -> val);
        }
        rightside(node -> right , level + 1 , ans);
        rightside(node -> left , level + 1 , ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        //TC:O(n)
        //SC:O(h)
        vector<int> ans;
        rightside(root , 0 , ans);
     // leftside(root , 0 , ans);
        return ans;
    }
};