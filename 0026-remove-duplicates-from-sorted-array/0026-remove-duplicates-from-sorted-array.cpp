class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            if(nums[left] != nums[right]){
                nums[left+1] = nums[right];
                left++;
            }
        }
        return left+1;
    }
};