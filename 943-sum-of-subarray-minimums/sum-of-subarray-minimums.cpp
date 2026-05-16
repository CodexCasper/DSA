class Solution {
private:
    vector<int> NSE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> PSEE(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);

        int n = arr.size();
        int mod = 1e9 + 7;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;

            long long freq = left * right;
            long long val = (freq * arr[i]) % mod;

            sum = (sum + val) % mod;
        }

        return sum;
    }
};