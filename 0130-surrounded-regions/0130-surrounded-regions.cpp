class Solution {
public:
//TC:O(m * n) , SC:O(m * n)
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {
    
    if(row < 0 || col < 0 || row >= m || col >= n)
        return false;
    
    return true;
}
void dfs(vector<vector<char>> &a , int n , int m , int row , int col) {

    a[row][col] = '#';

    for(int k = 0 ; k < 4 ; k++) {
        
        int newrow = row + dr[k];
        int newcol = col + dc[k];

        if(valid(newrow , newcol , n , m) && a[newrow][newcol] == 'O') {

            dfs(a , n , m , newrow , newcol);
        }
    }
    return;
}
    void solve(vector<vector<char>>& board) {

        int m = board.size(); // row
        int n = board[0].size(); // col

        //first row
        int i , j;
        for(j = 0 ; j < n ; j++) {

            if(board[0][j] == 'O')
              dfs(board , n , m , 0 , j);
        }

        //last row
        for( j = 0 ; j < n ; j++) {

            if(board[m-1][j] == 'O') 
              dfs(board , n , m , m-1 , j);
        }
        
        //first col
        for(i = 0 ; i < m ; i++) {

            if(board[i][0] == 'O')
               dfs(board , n , m , i , 0);
        }

        //last col 
        for(i = 0 ; i < m ; i++) {

            if(board[i][n-1] == 'O')
               dfs(board , n , m , i , n-1);
        }

        for(i = 0 ; i < m ; i++) {
            for(j = 0 ; j < n ; j++) {
                
                if(board[i][j] == '#') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};