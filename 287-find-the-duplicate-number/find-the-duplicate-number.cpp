class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*  //TC:O(n) , SC:O(n)
        unordered_map<int,int> hash;

        for(int num: nums){
            if(hash.find(num) != hash.end()) return num;

            hash[num] = 1;
        }
        return -1;
         */
        //TC:O(n) , SC:O(1)
        int slow = 0 , fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast){
                break;
            }
        } while(slow != fast);

        int n1 = 0;
        int n2 = slow;

        while(n1 != n2){
            n1 = nums[n1];
            n2 = nums[n2];
        }
        return n1;
    }
};