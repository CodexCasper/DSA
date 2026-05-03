class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //TC:O(n) , SC:O(n)
        /*
        1. Brute force checks all subarrays → O(n²), too slow.

2. Use prefix sum:
   Let sum = sum of elements from 0 → current index.

3. For any subarray ending at current index:
   sum(i → j) = prefix[j] - prefix[i-1]

4. We need:
   prefix[j] - prefix[i-1] = k
   ⇒ prefix[i-1] = prefix[j] - k

5. So at each index:
   check how many times (sum - k) appeared before.

6. Use hashmap to store:
   prefix sum → frequency

7. For each element:
   - update sum
   - if (sum - k) exists → add its frequency to count
   - store current sum in map

8. Initialize map with (0 → 1) to handle subarrays starting from index 0.
        */
        unordered_map<int , int> mpp;
        mpp[0] = 1;

        int currsum = 0;
        int cnt = 0;
        for(int x : nums){
            currsum += x;

            if(mpp.find(currsum - k) != mpp.end()){
                // we did this instead of +1 bcoz (mpp[currsum-k]) may have appeared multiple times
                //ie. 1 -1  1 -1  , k = 0
                //i   0  1  2  3
                //sum 1  0  1  0 
                //so here if sum = 0 , sum - k = 0 then mpp[0] = 2 which will be wrong for +1
                cnt += mpp[currsum-k];
            }
            mpp[currsum]++;
        }
        return cnt;
    }
};