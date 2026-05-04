class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //TC:O(n),SC:O(min(n,k)) bcoz for rem = sum%k max can be 0 -> k-1 but if n < k then min
        //It is asked to count subarrays where sum % k = 0 that means sum is divisible by k 
        //we know that using prefix sum sum(i -> j) = prefix[j] - prefix[i-1]
        //and we want (prefix[j] - prefix[i-1]) % k == 0
        //rearrange -> prefix[j] % k = prefix[i-1] % k , two prefix sum with same remainder => subarr divisible y k
        //prefix[j] % k = 2
        //prefix[i-1] % k = 2
        //then prefix[j] - prefix[i-1] = multiple of k ,so subarr sum divisible by k
        //ie. num = [4,5]
        //sum = 4 rem = 4
        //sum = 9 rem = 4
        //prefixsum[0] = 4 prefixsum[1] = 9 and 9 - 4 = 5  , divisible by 5

        unordered_map<int,int> mpp;
        mpp[0] = 1;

        int sum = 0 , cnt = 0;
        for(int x : nums){
            sum += x;

            int rem = sum % k;

            if(rem < 0) rem += k;

            if(mpp.find(rem) != mpp.end()){
                cnt += mpp[rem];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};