class Solution {
public:
int calcNextIdx(vector<int> &nums , int curr) {
    int n = nums.size();
    int next = curr;
    int step = nums[curr];
    if(step > 0) {
        next = (curr + step) % n;
    } else {
        int mod = step % n;
        int forward = n + mod;
        next = (curr + forward) % n;
    }
    return next;
}
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 0) continue;
            
            bool isPos = nums[i] > 0;
            int slow = i;
            int fast = i;

            do {
                slow = calcNextIdx(nums , slow);
                fast = calcNextIdx(nums , fast);

                if(isPos) {
                    if(nums[fast] < 0) 
                        break;
                } else {
                    if(nums[fast] > 0) break;
                }

                fast = calcNextIdx(nums , fast);
                
                if(isPos) {
                    if(nums[fast] < 0) 
                        break;
                } else {
                    if(nums[fast] > 0) break;
                }

                if(slow == fast){
                    //cycle isthere
                    if(slow != calcNextIdx(nums , slow)) {
                        return true;
                    }
                    break;
                }
            } while( slow != fast);
          
            int curr = i;

            if(isPos) {
                while(nums[curr] > 0) {
                    int next = calcNextIdx(nums , curr);
                    nums[curr] = 0;
                    curr = next;
                }
            } else {
                while(nums[curr] < 0) {
                    int next = calcNextIdx(nums , curr);
                    nums[curr] = 0;
                    curr = next;
                }
            }
        }
        return false;
    }
};