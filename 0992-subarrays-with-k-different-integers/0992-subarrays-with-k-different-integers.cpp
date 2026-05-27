class Solution {
private:
int countSubarr(vector<int> &nums , int k){
    int n = nums.size();
    int l = 0 , r = 0;
    int cnt = 0;
    unordered_map<int , int> mpp;
    while(r < nums.size()){
        mpp[nums[r]]++;

        while(mpp.size() > k){
            mpp[nums[l]]--;

            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);

            l++;
        }
        cnt += (r-l+1);
        r++;
    }
    return cnt;
}    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //TC:O(4*n) , SC:O(2*n)
        return countSubarr(nums, k) - countSubarr(nums,k-1);
    }
};