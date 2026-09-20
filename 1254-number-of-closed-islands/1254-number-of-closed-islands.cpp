class Solution {
public:
//TC:O(m * n) , SC:O( m* n)
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {

    if(row < 0 || col < 0 || row >= n || col >= m)
       return false;

    return true;   
}
void dfs(vector<vector<int>> &a , int n , int m , int row , int col , vector<vector<bool>> &visited) {

    a[row][col] = -1;
    visited[row][col] = -1;

    for(int k = 0 ; k < 4 ; k++) {

        int newrow = row + dr[k];
        int newcol = col + dc[k];

        if(valid(newrow , newcol , n , m) && a[newrow][newcol] == 0) {
            dfs(a , n , m , newrow , newcol , visited);
        }
    }
    return;
}
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int i , j;
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        int cnt = 0;
        //first row
        for(j = 0 ; j < m ; j++) {

            if(grid[0][j] == 0) 
                dfs(grid , n , m , 0 , j , visited);
        }
        //last row
        for(j = 0 ; j < m ; j++) {

            if(grid[n-1][j] == 0)
                dfs(grid ,n , m, n-1 , j , visited);
        }
        //first column
        for(i = 0 ; i < n ; i++) {

            if(grid[i][0] == 0) 
                dfs(grid , n , m , i , 0, visited);
        }
        //last column
        for(i = 0 ; i < n ; i++) {

            if(grid[i][m-1] == 0)
                dfs(grid , n , m , i , m-1 , visited);
        }

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {

                if(grid[i][j] == 0 && !visited[i][j]) {
                    cnt++;
                    dfs(grid , n , m , i , j, visited);
                }
            }
        }
        return cnt;
    }
};