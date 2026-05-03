class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /*
        1. Goal: Find index i such that
   sum(0 → i-1) == sum(i+1 → n-1)

2. Instead of recomputing sums every time:
   → Precompute prefix and suffix sums

3. prefix[i] = sum of elements before i
   suffix[i] = sum of elements after i

4. For each index i:
   if(prefix[i] == suffix[i]) → return i

5. If no such index → return -1
        */
        int n = nums.size();

        vector<int> prefixsum(n+1,0);
        vector<int> suffixsum(n+1,0);

        for(int i = 1; i <= n ; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i-1];
        }

        for(int i = n-2 ; i >= 0 ; i--){
            suffixsum[i] = suffixsum[i+1] + nums[i+1];
        }

        for(int i = 0 ; i < n ; i++){
            int ans1 = prefixsum[i];
            int ans2 = suffixsum[i];

            if(ans1 == ans2) return i;
        }
        return -1;
    }
};