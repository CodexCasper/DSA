class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //TC:O(n) , SC:O(1)
        int XOR = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            XOR = XOR ^ nums[i];
        }
        return XOR;
    }
};