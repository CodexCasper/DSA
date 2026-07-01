/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};

        unordered_map<TreeNode* , TreeNode*> parentmap;
        mapParentNode(root , parentmap);

        return bfsFromTarget(target , parentmap , k);
    }
    void mapParentNode(TreeNode* root , unordered_map<TreeNode*,TreeNode*> &parentmap){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parentmap[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentmap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> bfsFromTarget(TreeNode* target , 
    unordered_map<TreeNode* , TreeNode*> &parentmap, int k){
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int currentlevel = 0;

        while(!q.empty()){
            int size = q.size();

            if(currentlevel++ == k) break;

            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end()){
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if(parentmap.count(node) && visited.find(parentmap[node]) == visited.end()){
                    visited.insert(parentmap[node]);
                    q.push(parentmap[node]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};