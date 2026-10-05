class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        pq.push({0 , 0});

        int sum = 0;

        vector<int> vis(n , 0);

        while(!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if(vis[node] == 1) continue;

            vis[node] = 1;
            sum += wt;

            for(int i = 0 ; i < n ; i++) {

                if(vis[i] == 0) {

                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);

                    pq.push({dist , i});
                }
            }
        }
        return sum;
    }
};