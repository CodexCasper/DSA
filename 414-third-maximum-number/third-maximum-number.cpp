class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        unordered_set<int>st;

       for(int i = 0 ; i < nums.size() ; i++) {

        if(st.count(nums[i])) continue;

        st.insert(nums[i]);
        minheap.push(nums[i]);

        if(minheap.size() > 3) {
            minheap.pop();
        }
       }
       if(minheap.size() < 3) {

        while(minheap.size() > 1) minheap.pop();
        return minheap.top();
       }
       return minheap.top();
    }
};