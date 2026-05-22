class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //TC:O(N) , SC:O(1)
        int n = nums.size();
        int l = 0 , maxlen = 0 , zeroes = 0;
        for(int r = 0 ; r < n ; r++){
            if(nums[r] == 0) zeroes++;
            //while(zeroes > k)  better approach , will add one more N to tc 
            if(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
                int len = r - l + 1;
                maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};