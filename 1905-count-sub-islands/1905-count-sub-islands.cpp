class Solution {
public:

vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {

    if(row < 0 || col < 0 || row >= n || col >= m)
        return false;

    return true;    
}
bool dfs(vector<vector<int>> &g1 , vector<vector<int>> &g2 , int n , int m , int row , int col) {
    
    bool validIsland = true;

    if(g1[row][col] == 0)
        validIsland = false;

    g2[row][col] = -1;

    for(int k = 0 ; k < 4 ; k++) {

        int newrow = row + dr[k];
        int newcol = col + dc[k];

        if(valid(newrow , newcol , n , m) &&
        g2[newrow][newcol] == 1
        ) {
           bool child = dfs(g1 , g2 , n , m ,newrow , newcol);

           if(child == false)
             validIsland = false;
        }
    }
    return validIsland;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid1[0].size();

        int cnt = 0;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {

                if(grid2[i][j] == 1) {
                    
                    if(dfs(grid1, grid2 , n , m , i , j))
                      cnt++;
            }
        }
    }
    return cnt;
    }
};