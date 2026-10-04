class Solution {
public:
//TC:O(V + E(log V))
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0 ; i < edges.size() ; i++) {

            int src = edges[i][0];
            int dest = edges[i][1];
            double prob = succProb[i];

            adj[src].push_back({dest , prob});
            adj[dest].push_back({src , prob});
        }

        priority_queue<pair<double,int>> pq;
        vector<double> prob(n , 0.0);

        prob[start_node] = 1.0;
        pq.push({1.0 , start_node});

        while(!pq.empty()) {

            auto p = pq.top();;
            pq.pop();

            double currProb = p.first;
            int node = p.second;

            if(currProb < prob[node]) continue;

            if(node == end_node) return currProb;

            for(int j = 0 ; j < adj[node].size() ; j++) {

                int neigh = adj[node][j].first;
                double edgeProb =  adj[node][j].second;

                double newProb = currProb * edgeProb;

                if(newProb > prob[neigh]) {

                    prob[neigh] = newProb;
                    pq.push({newProb , neigh});
                }
            }
        }
        return 0.0;
    }
};