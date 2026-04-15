class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //TC:O(N) . SC:O(1)
        // [5 , -3 , 5]
        // currmax = 0 maxsum = nums[0] = 5
        // currmin = 0 maxmin = nums[0] = 5
        // it1 ->currmax =max(5,0+5) =5 maxsum =max(5,5)=5 currmin =min(5,5)=5 min=min(5,5)=5
        int total = 0;

        int maxending = nums[0] , currmax = 0;
        int minending = nums[0] , currmin = 0;

        for(int x : nums){
            total += x;

            currmax = max(x , currmax + x);
            maxending = max(maxending , currmax);

            currmin = min(x , currmin + x);
            minending = min(minending , currmin);
        }
        if(maxending < 0) return maxending;
        return max(maxending , total - minending);
    }
};