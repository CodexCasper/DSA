class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //we took n+1 bcoz prefix[0] == 0 bcoz there are no elements behind it
        //  1 2 3 4 5
        //i        0   1   2   3   4   5
        //prefix   0   1   3   6  10  15

        //tC:O(n) , sC:O(2n) == O(n)

        int n = nums.size();
        vector<int> prefixsum(n+1,0);
        vector<int> suffixsum(n+1,0);

        for(int i = 1 ; i < n ; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i-1];
        }
        for(int i = n-2 ; i >= 0 ; i--){
            suffixsum[i] = suffixsum[i+1] + nums[i+1];
        }

        for(int i = 0 ; i < n ; i++){
            int prefix = prefixsum[i];
            int suffix = suffixsum[i];

            if(prefix == suffix) return i;
        }
        return -1;
    }
};