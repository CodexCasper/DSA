class Solution {
private:
vector<int> findNSE(vector<int> &arr){
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;
    for(int i = n - 1 ; i >= 0 ; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> findPSEE(vector<int> &arr){
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> findNGE(vector<int> &arr){
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;
    for(int i = n - 1; i >= 0 ; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> findPGEE(vector<int> &arr){
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;
    for(int i = 0 ; i < n ; i++){
        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
long long sumSubarrMin(vector<int> &arr){
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    int n = arr.size();
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        int left = i - psee[i];
        int right = nse[i] - i;
        long long freq = left * right * 1LL;
        long long val = freq*1LL*arr[i];
        sum += val;
    }
    return sum;
}
long long sumSubarrMax(vector<int> &arr){
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);

    int n = arr.size();
    long long sum = 00;
    for(int i = 0 ; i < n ; i++){
        int left = i - pgee[i];
        int right = nge[i] - i;
        long long freq = left * right * 1LL;
        long long val = freq*arr[i]*1LL;
        sum += val;
    }
    return sum;
}
public:
    long long subArrayRanges(vector<int>& nums) {
        return(sumSubarrMax(nums) - sumSubarrMin(nums));
    }
};