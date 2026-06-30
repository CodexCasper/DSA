class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int maxwidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){

            int size = q.size();
            long long minIndex = q.front().second;

            long long first = 0;
            long long last = 0;

            for(int i = 0; i < size; i++){
                long long currInd = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0)
                    first = currInd;
                if(i == size - 1)
                    last = currInd;

                if(node->left)
                    q.push({node->left, 2 * currInd + 1});
                if(node->right)
                    q.push({node->right, 2 * currInd + 2});
            }
            maxwidth = max(maxwidth, (int)(last - first + 1));
        }
        return maxwidth;
    }
};