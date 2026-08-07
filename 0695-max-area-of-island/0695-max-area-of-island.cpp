class Solution {
public:
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int i , int j , int n , int m){
     if(i < 0 || i >= n || j < 0 || j >= m){
        return false;
     }
     return true;
}

int dfs(vector<vector<int>>& grid , int row , int col , vector<vector<bool>>& vis) {
    vis[row][col] = true;

    int n = grid.size();
    int m = grid[0].size();
    
    int area = 1;
    for(int k = 0 ; k < 4 ; k++) {
        int newrow = row + dr[k];
        int newcol = col + dc[k];

        if(valid(newrow , newcol , n , m) &&
           grid[newrow][newcol] == 1 &&
           !vis[newrow][newcol]) {

            area += dfs(grid , newrow , newcol , vis);
           }
    }
    return area;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //TC:O(n * m) , SC:O(n * m)
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int maxarea = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {

                    int area = dfs(grid , i , j , vis);
                    maxarea = max(maxarea , area);
                }
            }
        }
        return maxarea;
    }
};