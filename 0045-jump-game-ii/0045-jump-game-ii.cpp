class Solution {
public:
    int jump(vector<int>& nums) {
        //tC:O(n) , SC:O(1)
        int jumps = 0 , currEnd = 0 , farthestPt = 0;

        for(int i = 0 ; i < nums.size() - 1 ; ++i){
            farthestPt = max(farthestPt , i + nums[i]);

            if(i == currEnd){
                jumps++;

                currEnd = farthestPt;
            }
        }
        return jumps;
    }
};