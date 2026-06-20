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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       //   vertical  levels    multinodes  , multinode store value in sorted order
       //TC:O(n logn)
       //SC:O(n)
        map<int , map<int , multiset<int>>> datast;
        queue<pair<TreeNode* , pair<int , int>>> q;

        // ({element , { vertical , level }})
        q.push({root , {0,0}});
        while(!q.empty()){

            auto it1 = q.front();
            q.pop();

            TreeNode* node = it1.first;
            int vertical = it1.second.first;
            int level = it1.second.second;

            datast[vertical][level].insert(node -> val); 

            if(node -> left)
                q.push({node -> left , {vertical - 1 , level + 1}});
            
            if(node -> right)
                q.push({node -> right , {vertical + 1 , level + 1}});
        }

        vector<vector<int>> ans;
        for(auto p : datast){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};