class Solution {
public:

vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {

    if(row < 0 || col < 0 || row >= n || col >= m) 
        return false;

    return true;    
}
int dfs(vector<vector<int>>& grid , int n , int m , int row , int col) {

    grid[row][col] = -1;

    int perimeter = 0;
    for(int k = 0 ; k < 4 ; k++) {

        int newrow = row + dr[k];
        int newcol = col + dc[k];

        if(!valid(newrow , newcol , n , m)) {
            perimeter++;
        }
        else if(grid[newrow][newcol] == 0) {
            perimeter++;
        }
        else if(grid[newrow][newcol] == 1) {

            perimeter += dfs(grid , n , m , newrow , newcol);
        }
    }
    return perimeter;
}
    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {

                if(grid[i][j] == 1) {
                   return dfs(grid , n , m , i , j);
                }
            }
        }
        return 0;
    }
};