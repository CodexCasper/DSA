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
    int findMinDis(TreeNode* target , map<TreeNode*, TreeNode*> &parentmap){
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*,int> visited;
        visited[target] = 1;
        int time = 0;

        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i = 0 ; i < size ; i++){
                auto node = q.front();
                q.pop();

                if(node -> left && !visited[node -> left]){
                    flag = 1;
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                if(node -> right && !visited[node->right]){
                    flag = 1;
                    visited[node->right] = 1;
                    q.push(node->right);
                }
                if(parentmap[node] && !visited[parentmap[node]]){
                    flag = 1;
                    visited[parentmap[node]] = 1;
                    q.push(parentmap[node]);
                }
            }
            if(flag) time++;
        }
        return time;
    }
    TreeNode* bfsToMapParents(TreeNode* root , 
    map<TreeNode*, TreeNode*> &parentmap, int &start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;

        while(!q.empty()){
            TreeNode* node = q.front();

            if(node-> val == start) res = node;
            q.pop();

            if(node -> left){
                parentmap[node->left] = node;
                q.push(node -> left);
            }
            if(node -> right){
                parentmap[node->right] = node;
                q.push(node -> right);
            }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parentmap;
        TreeNode* target = bfsToMapParents(root , parentmap , start);

        int maxi = findMinDis(target , parentmap);
        return maxi;
    }
};