class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //TC:O(n) , SC:O(1)
        int maxending = nums[0];
        int minending = nums[0];
        int ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int choice1 = nums[i];
            int choice2 = minending * nums[i];
            int choice3 = maxending * nums[i];

            maxending = max(choice1 , max(choice2,choice3));
            minending = min(choice1, min(choice2,choice3));
            ans = max(ans,max(minending,maxending));
        }
        return ans;
    }
};