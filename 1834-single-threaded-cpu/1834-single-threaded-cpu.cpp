class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0];
        });

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minheap;

        vector<int> ans;
        int i = 0;
        long long time = 0;

        while (i < n || !minheap.empty()) {

            if (minheap.empty() && i < n && tasks[indices[i]][0] > time) {
                time = tasks[indices[i]][0];
            }

            while (i < n && tasks[indices[i]][0] <= time) {
                int idx = indices[i];

                minheap.push({
                    tasks[idx][1],
                    idx
                });

                i++;
            }

            auto task = minheap.top();
            minheap.pop();

            int processingTime = task.first;
            int originalIndex = task.second;

            ans.push_back(originalIndex);
            time += processingTime;
        }

        return ans;
    }
};