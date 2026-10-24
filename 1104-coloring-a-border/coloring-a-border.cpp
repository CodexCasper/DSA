class Solution {
public:
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {
    
    if(row < 0 || col < 0 || row >= n || col >= m) {
        return false;
    }
    return true;
}
void dfs(vector<vector<int>>& grid , int row , int col , int color , vector<vector<int>>& result , vector<vector<bool>>& vis , int ogc) {

    int n = grid.size();
    int m = grid[0].size();

    int same = 0;
    vis[row][col] = true;

    for(int k = 0 ; k < 4 ; k++) {
        int nr = row + dr[k];
        int nc = col + dc[k];

        if(valid(nr , nc , n , m) && grid[nr][nc] == ogc){
            same++;

            if(valid(nr , nc , n , m) && grid[nr][nc] == ogc && !vis[nr][nc]) {
                dfs(grid , nr , nc , color , result , vis , ogc);;
            }
        } 
    }
    if(same < 4) {
        result[row][col] = color;
    }
}
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result = grid;
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int originalcolour = grid[row][col];

        if(originalcolour == color)
           return result;

        if(!vis[row][col]) {

            dfs(grid , row , col , color , result , vis ,originalcolour);
        }
        return result;   
    }
};