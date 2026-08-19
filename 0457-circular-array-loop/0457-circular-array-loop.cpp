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
            unordered_set<int> st;
            st.insert(i);
            bool isPos = nums[i] > 0;

            int curr = i;
            while(true) {
                int next = calcNextIdx(nums , curr);
                if(isPos) {
                    if(nums[next] < 0) {
                        break;
                    }
                    else {
                        if(st.contains(next)){
                            if(curr != next) return true;
                            else break;
                        } 
                        st.insert(next);
                    }
                }
                else {
                    if(nums[next] > 0) {
                        break;
                    }
                    else {
                        if(st.contains(next)){
                            if(curr != next) return true;
                            else break;
                        }
                        st.insert(next);
                    }
                }
                curr = next;
            }
            curr = i;

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