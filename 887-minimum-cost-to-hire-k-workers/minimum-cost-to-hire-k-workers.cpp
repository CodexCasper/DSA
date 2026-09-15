class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<pair<double,int>> workers;

        for(int i = 0 ; i < n ; i++) {

            double ratio = ((double) wage[i] / quality[i]);

            workers.push_back({ratio ,  quality[i]});
        }
        sort(workers.begin() , workers.end());

        priority_queue<int> maxheap;

        int totalqal = 0;
        double ans = DBL_MAX;

        for(int i = 0 ; i < workers.size() ; i++) {

            double ratio = workers[i].first;
            int q = workers[i].second;

            maxheap.push(q);
            totalqal += q;

            if(maxheap.size() > k) {
                totalqal -= maxheap.top();
                maxheap.pop();
            }

            if(maxheap.size() == k) {
                ans = min(ans , ratio * totalqal);
            }
        }
        return ans;
    }
};