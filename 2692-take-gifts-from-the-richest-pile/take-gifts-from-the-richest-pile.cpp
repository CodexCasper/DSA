class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        priority_queue<int> maxheap;

        for(int i = 0 ; i < n ; i++) {
            maxheap.push(gifts[i]);
        }

        vector<int> ans;
        while(k--) {
            int p = maxheap.top();
            maxheap.pop();

            int newvalue = sqrt(p);
            maxheap.push(newvalue);
        }
        long long sum = 0;
        while(!maxheap.empty()) {
            sum += maxheap.top();
            maxheap.pop();
        }
        return sum;
    }
};