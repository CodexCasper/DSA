class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //TC:O( V + E) 
        //SC:O(V + E)
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses , 0);

        int n = prerequisites.size();
        for(int i = 0 ; i < n ; i++) {

            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];

            adj[src].push_back(dest);
            indegree[dest]++;
        }

        queue<int> q;
        for(int i = 0 ; i < indegree.size() ; i++) {

            if(indegree[i] == 0) {

                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()) {

            int node = q.front();
            q.pop();
            count++;

            for(int j = 0 ; j < adj[node].size() ; j++) {

                int neigh = adj[node][j];
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
        return count == numCourses;
    }
};