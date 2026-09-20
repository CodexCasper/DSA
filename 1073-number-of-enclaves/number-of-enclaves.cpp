class Solution {
public:
//TC:O(m * n) , SC:O(m * n)
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {

    if(row < 0 || col < 0 || col >= n || row >= m) 
        return false;
    
    return true;
}
void dfs(vector<vector<int>> &a , int n , int m , int row , int col) {

    a[row][col] = -1;

    for(int k = 0 ; k < 4 ; k++) {

        int newrow = row + dr[k];
        int newcol = col + dc[k];

        if(valid(newrow , newcol , n , m) && a[newrow][newcol] == 1) {
            dfs(a , n , m , newrow , newcol);
        }
    }
    return;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int i , j;
        int counter = 0;

        //first row
        for(j = 0 ; j < n ; j++) {

            if(grid[0][j] == 1)
              dfs(grid , n , m , 0 , j);
        }
        //last row
        for(j = 0 ; j < n ; j++) {

            if(grid[m-1][j] == 1)
              dfs(grid , n , m , m-1 , j);
        }
        //first col
        for(i = 0 ; i < m ; i++) {

            if(grid[i][0] == 1)
             dfs(grid , n , m , i , 0);
        }
        //last col
        for(i = 0 ; i < m ; i++) {

            if(grid[i][n-1] == 1)
              dfs(grid , n , m , i , n-1);
        }
        for( i = 0 ; i < m ; i++) {
            for(j = 0 ; j < n ;j++) {

                if(grid[i][j] == 1)
                  counter++;
            }
        }
        return counter;
    }
};