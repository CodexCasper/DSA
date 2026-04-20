class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       /* //TC:O(n*n) , SC:O(1) won't work bcoz of size of n
        int n = nums.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            for(int j = i ; j < n ; j++){
                sum += nums[j];
                if(sum == k){
                    cnt++;
                }
            }
        }
        return cnt;
        */
        ///TC:O(n) , SC:O(n)
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int sum = 0;
        int cnt = 0;
        for(int x : nums){
            sum += x;

            if(mpp.find(sum - k) != mpp.end()){
                cnt += mpp[sum-k];
            }

            mpp[sum]++;
        }
        return cnt;
    }
};