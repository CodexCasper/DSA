class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //TC:O(V + E + V log V) , SC:O(V  + E)
        int v = graph.size();
        vector<vector<int>> adj(v);
        vector<int> indegree(v , 0);

        for(int i = 0 ; i < v ; i++) {
            for(int j = 0 ; j < graph[i].size() ; j++) {

                int neigh = graph[i][j];
                adj[neigh].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < indegree.size() ; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()) {

            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int j = 0 ; j < adj[node].size() ; j++) {

                int neigh = adj[node][j];
                indegree[neigh]--;

                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        sort(res.begin() , res.end());
        return res;   
    }
};