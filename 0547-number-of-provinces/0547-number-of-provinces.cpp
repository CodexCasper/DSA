class Solution {
public:
void dfs(vector<vector<int>>& isConnected, int city , vector<bool>& vis) {
    int n = isConnected.size();
    vis[city] = true;
    for(int nextCity = 0 ; nextCity < n ; nextCity++) {
        if(isConnected[city][nextCity] == 1 &&
           !vis[nextCity]) {

            dfs(isConnected , nextCity , vis);
           }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        int province = 0;
        vector<bool> vis(n , false);
        for(int city = 0 ; city < n ; city++) {
            if(!vis[city]) {
                province++;
                dfs(isConnected , city , vis);
            }
        }
        return province;
    }
};