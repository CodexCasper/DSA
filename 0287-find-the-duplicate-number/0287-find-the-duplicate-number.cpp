class Solution {
public:
//TC:O(n) , SC:O(n)
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int num: nums){
            if(hash.find(num) != hash.end()) return num;

            hash[num] = 1;
        }
        return -1;
    }
};