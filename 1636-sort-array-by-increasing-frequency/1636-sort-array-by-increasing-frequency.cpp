class cmp {
    public:
    bool operator()(pair<int,int>&a , pair<int,int>&b) {

        if(a.second != b.second) {
            return a.second > b.second;
        }
         return a.first < b.first;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int num: nums) {
            mpp[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> minheap;

        for(auto it: mpp) {

            minheap.push({it.first , it.second});
        }

        vector<int> ans;

        while(!minheap.empty()) {

            int num = minheap.top().first;
            int freq = minheap.top().second;

            minheap.pop();
            while(freq--) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};