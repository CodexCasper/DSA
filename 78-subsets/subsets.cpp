class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //TC:O(n * 2 pow n) , sC:O(2 pow n * n) bcoz 2 pow n is no of subsets and n is there size
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;

        for(int num = 0 ; num <= subsets-1 ; num++){
            vector<int> subset;
            for(int j = 0 ; j < n ; j++){
                if(num & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};