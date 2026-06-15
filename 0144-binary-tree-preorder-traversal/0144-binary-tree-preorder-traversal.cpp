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
void preorder(TreeNode* root , vector<int> &ans){
    /*
    //TC:O(n) , SC:O(h) h = height of the tree due to recursion stack
    if(root == NULL) return;

    ans.push_back(root->val);
    preorder(root->left,ans);
    preorder(root->right,ans);
    */
}
    vector<int> preorderTraversal(TreeNode* root) {
        /*
        vector<int> ans;
        preorder(root , ans);
        return ans;
        */
        /*
        O(n)

        Why?

        Every node is pushed into the stack exactly once.
        Every node is popped exactly once.
        Every node is processed exactly once.
        Push operations = n
        Pop operations = n
        Visit operations = n
        O(n + n + n) = O(n)
        sc: balanced tree O(log n) , skewed tree O(n)
        */
        vector<int> pre;

        if(root == NULL) return pre;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            pre.push_back(curr->val);

             if(curr->right){
                st.push(curr->right);
            }

            if(curr->left){
                st.push(curr->left);
            }
        }
        return pre;
    }
};