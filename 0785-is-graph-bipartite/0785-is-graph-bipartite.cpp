class Solution {
public:
//TC:O( V + E) , SC:O(V)
bool res = true;
void dfs(vector<vector<int>> &adj , int node , int color , vector<int>& colors) {
   
    colors[node] = color;
    for(int j = 0 ; j < adj[node].size() ; j++) {
        
        int neigh = adj[node][j];

        if(colors[neigh] != -1 && colors[neigh] == color) {
            res = false;
        }
        if(colors[neigh] == -1) {
            dfs(adj , neigh , 1 - color, colors);
        }
    }
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n , -1);

        for(int i = 0 ; i < n ; i++) {
            //now it is given that graph can be multiple components , that mean all the vertices may not be connected with each other
            //that means when we will loop through all vertices all the graph we will not start with vertex = 0 instead we initialized all vertices with -1
            //and loop on those which are not visited
            if(colors[i] == -1) {
                dfs(graph , i , 0 , colors);
            }
        }
        return res;
    }
};