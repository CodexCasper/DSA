class Solution {
public:
//TC:O(V + E) , SC:O(V + E)
bool ans = true;
void dfs(vector<vector<int>>& adj , int node , int color , vector<int>& colors) {

    colors[node] = color;

    for(int j = 0; j < adj[node].size() ; j++) {

        int neigh = adj[node][j];

        if(colors[neigh] != -1 && colors[neigh] == color) {
            ans = false;
        }
        if(colors[neigh] == -1) {
            dfs(adj , neigh , 1 - color , colors);
        }
    }
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for(int i = 0 ; i < dislikes.size() ; i++) {

            int src = dislikes[i][0];
            int dest = dislikes[i][1];

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }

        vector<int> colors(n+1, -1);

        for(int i = 1 ; i <= n ; i++) {

            if(colors[i] == -1) {
                dfs(adj , i , 0 , colors);
            }
        }
        return ans;
    }
};