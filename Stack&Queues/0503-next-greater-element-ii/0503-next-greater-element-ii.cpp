class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //TC:O(4n)
        //sc:O(2n) + O(n)
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        //O(2n)
        for(int i = 2*n - 1 ; i >= 0 ; i--){

            int ind = i % n;
            int currEle = nums[ind];
            //O(2n) atmost can pop 2n elements
            while(!st.empty() && st.top() <= currEle){
                st.pop();
            }
            if( i < n ){
                ans[i] = st.empty() ? -1 : st.top();
            }
            //O(2n) atmost can push 2n elements
            st.push(currEle);
        }
        return ans;
    }
};