class Solution {
public:
//TC:O(N) , SC:O(h)
    struct NodeValues {
        int minNode, maxNode, maxSum;

        NodeValues(int minNode, int maxNode, int maxSum) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSum = maxSum;
        }
    };

    int ans = 0;

    NodeValues largestBST(TreeNode* root) {

        if (root == NULL)
            return NodeValues(INT_MAX, INT_MIN, 0);

        auto left = largestBST(root->left);
        auto right = largestBST(root->right);

        if (left.maxNode < root->val &&
            root->val < right.minNode) {

            int sum = left.maxSum + right.maxSum + root->val;

            ans = max(ans, sum);

            return NodeValues(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                sum
            );
        }

        return NodeValues(
            INT_MIN,
            INT_MAX,
            max(left.maxSum, right.maxSum)
        );
    }

    int maxSumBST(TreeNode* root) {
        largestBST(root);
        return ans;
    }
};