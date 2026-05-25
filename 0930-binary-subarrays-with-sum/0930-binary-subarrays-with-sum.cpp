class Solution {
private:
int atMost(vector<int> &nums , int goal){
     //TC:O(2N) * 2 , SC:O(1)
        if(goal < 0) return 0;

        int l = 0;
        int sum = 0 , count = 0;
        for(int r = 0 ; r < nums.size() ; r++){
            sum += nums[r];
            
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            count = count + (r - l + 1);
        }
        return count;
}    
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums , goal) - atMost(nums , goal - 1);
    }
};