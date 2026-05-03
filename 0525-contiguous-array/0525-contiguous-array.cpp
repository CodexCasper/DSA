class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>mpp;
        int zero = 0 , one = 0;
        int result = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) zero++;
            else one++;

            int diff = zero - one;
            if(diff == 0){
                result = max(result , i+1);
                continue;
            }

            if(mpp.find(diff) == mpp.end()){
                mpp[diff] = i;
            }
            else{
                int len = i - mpp[diff];
                result = max(result , len);
            }
        }
        return result;
    }
};

/*
1. Problem:
   Find longest subarray with equal number of 0s and 1s.

2. Key Transformation:
   Treat:
     0 → -1 (Red)
     1 → +1 (Green)

   Now problem becomes:
     Find longest subarray with sum = 0

3. Running Difference:
   diff = (#Green - #Red)
        = prefix sum

4. Red-Green Theory (Core Insight):
   If at index i and j the diff is same:
     diff[i] == diff[j]

   Then:
     The segment between (j+1 → i) has equal Red and Green
     ⇒ sum = 0 ⇒ valid subarray

   (Because no net change in difference)

5. Strategy:
   Use hashmap to store:
     diff → first index where it appeared

6. While iterating:
   - Update diff using current element
   - Check:

   a) If diff == 0:
      Subarray from 0 → i is balanced
      length = i + 1

   b) If diff seen before:
      length = i - first_index_of_diff
      update max length

   c) If diff not seen:
      store it in hashmap

7. Important Rule:
   Store only FIRST occurrence of diff
   (to maximize subarray length)

8. Return maximum length
*/