class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //TC:O(n) , SC:O(n)
        int n = nums.size();
        int zero = 0 , one = 0;
        unordered_map<int,int> mpp;
        int result = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) zero++;
            else one++;

            int diff = one - zero;
            if(diff == 0){
                result = max(result , i + 1);
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