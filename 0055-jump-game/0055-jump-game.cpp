class Solution {
public:
    bool canJump(vector<int>& nums) {
        //TC:O(n) , SC:O(1)
        int maxInd = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if( i > maxInd ) return false;
            maxInd = max(maxInd , i + nums[i]);
        }
        return true;
    }
};