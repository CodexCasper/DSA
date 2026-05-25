class Solution {
private:
int countSubarr(vector<int> &nums , int k) {
    //TC:O(2N) , SC:O(1)
        if(k < 0) return 0;

        int left = 0;
        int sum = 0 , count = 0;

        for(int right = 0 ; right < nums.size() ; right++){
            sum += nums[right] % 2;

            while(sum > k){
                sum -= nums[left] % 2;
                left++;
            }
            count += right - left + 1;
        }
        return count;
}    
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ///TC:O(2N) * 2 , SC:O(1)
        return countSubarr(nums,k) - countSubarr(nums , k - 1);
    }
};