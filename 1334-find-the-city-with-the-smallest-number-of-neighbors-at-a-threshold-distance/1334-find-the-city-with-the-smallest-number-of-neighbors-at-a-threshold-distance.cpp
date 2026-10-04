class Solution {
public:
//TC:O(V(V+E) log V) , SC:O( V + E)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> a(n);

        for(int i = 0 ; i < edges.size() ; i++) {

            int src = edges[i][0];
            int dest = edges[i][1];
            int wt = edges[i][2];

            a[src].push_back({dest , wt});
            a[dest].push_back({src , wt});
        }
        
        int ans = -1;
        int mincount = INT_MAX;

        for(int src = 0 ; src < n ; src++) {

            priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> 
            pq;
            vector<int> dist(n , INT_MAX);
            dist[src] = 0;
            pq.push({0 , src});

            while(!pq.empty()) {

                auto p = pq.top();
                pq.pop();

                int d = p.first;
                int node = p.second;

                if(d > dist[node]) continue;

                for(int j = 0 ; j < a[node].size() ; j++) {

                    int neigh = a[node][j].first;
                    int weight = a[node][j].second;

                    if(d + weight < dist[neigh]) {
                        dist[neigh] = d + weight;
                        pq.push({dist[neigh] , neigh});
                    }
                }
            }
            int count = 0;
            for(int i = 0 ; i < n ; i++) {

                if(i != src && dist[i] <= distanceThreshold) {
                    count++;
                }
            }
            if(count <= mincount) {
                mincount = count;
                ans = src;
            }   
        }
        return ans;
    }
};