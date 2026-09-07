class cmp {
public:
    bool operator()(pair<int,string> &a, pair<int,string> &b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mpp;

        for(string word : words) {
            mpp[word]++;
        }

        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            cmp
        > minheap;

        for(auto it : mpp) {

            minheap.push({it.second, it.first});

            if(minheap.size() > k) {
                minheap.pop();
            }
        }

        vector<string> res;

        while(!minheap.empty()) {
            res.push_back(minheap.top().second);
            minheap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};