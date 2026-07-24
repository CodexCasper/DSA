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
    int maxPathSum(TreeNode* root) {
        //TC:O(N) , SC:O(h) height of tree
        int maxsum = INT_MIN;
        dfs(root , maxsum);

        return maxsum;
    }
    int dfs(TreeNode* root , int& maxsum){
        if(root == NULL) return 0;

        int left = max(0 , dfs(root -> left , maxsum));
        int right = max(0 , dfs(root -> right , maxsum));

        maxsum = max(maxsum , left + right + root->val);

        return max(left , right) + root->val;
    }
};