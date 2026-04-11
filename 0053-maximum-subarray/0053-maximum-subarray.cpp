class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //tC:O(n) in worst case we will traverse till the end , SC:O(1) no extra space used
        int bestending = nums[0] , ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int choice1 = bestending + nums[i];
            int choice2 = nums[i];

            bestending = max(choice1,choice2);
            ans = max(ans,bestending);
        }
        return ans;
    }
};