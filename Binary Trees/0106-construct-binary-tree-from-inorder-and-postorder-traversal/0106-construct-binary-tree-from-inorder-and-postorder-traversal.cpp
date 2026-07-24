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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //TC:O(n) , SC:O(1)
        if(postorder.size() != inorder.size()) return NULL;

        map<int ,int> mpp;

        for(int i = 0 ; i < inorder.size(); ++i){
            mpp[inorder[i]] = i;
        }
        return buildTreePostIn(inorder , 0 , inorder.size() - 1,
                               postorder , 0 , postorder.size() - 1,mpp);
    }

    TreeNode* buildTreePostIn(vector<int> &inorder, int InStart ,int InEnd,
                              vector<int> &postorder, int PStart , int PEnd,map<int,int> &mpp){
                                
                                if(InStart > InEnd || PStart > PEnd) return NULL;

                                TreeNode* root = new TreeNode(postorder[PEnd]);

                                int inRoot = mpp[root -> val];
                                int numsleft = inRoot - InStart;

                                root -> left = buildTreePostIn(inorder,InStart,inRoot -1 , postorder , PStart , PStart + numsleft -1 , mpp);

                                root -> right = buildTreePostIn(inorder , inRoot +1,
                                InEnd , postorder , PStart + numsleft , PEnd -1 ,mpp);
                                return root;
                              }
                              
};