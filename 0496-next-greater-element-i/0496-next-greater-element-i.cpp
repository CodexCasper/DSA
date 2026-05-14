class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //TC:O(n + m) because every element of `nums2` is pushed and popped from stack at most once, and every element of `nums1` is checked once using hashmap lookup.
        //SC:O(n + m)
        unordered_map<int,int> mpp;
        int n = nums2.size();
        stack<int> st;
        for(int i = n - 1 ; i >= 0 ; i--){

            int num = nums2[i];
            while(!st.empty() && st.top() <= num) st.pop();
            if(st.empty()) 
                mpp[num] = -1;
            else 
                mpp[num] = st.top();  
            st.push(num);      
        }

        vector<int> ans;
        for(int x : nums1) ans.push_back(mpp[x]);
        return ans;
    }
};