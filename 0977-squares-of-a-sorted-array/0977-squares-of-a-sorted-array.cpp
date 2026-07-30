class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*for( int i = 0 ; i < nums.size() ; i++ ){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
        */
        vector<int> ans(nums.size(),0);
        int n = nums.size();
        int left = 0, right = n-1;
        for( int i = n-1 ; i >= 0 ; i-- ){
            if( abs(nums[right]) < abs(nums[left]) ){
                ans[i] = nums[left] * nums[left];
                left++;
            }
            else if ( abs(nums[right]) > abs(nums[left]) ){
                ans[i] = nums[right]*nums[right];
                right--;
            }
            else{
                ans[i] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};