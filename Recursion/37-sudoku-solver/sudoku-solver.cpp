class Solution {
public:

bool solve(vector<vector<char>> &board){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){

            if(board[i][j] == '.'){
                for(char c = '1'; c <= '9' ; c++){
                    if(isValid(board , i , j , c)){
                        board[i][j] = c;

                        if(solve(board) == true)
                            return true;

                        board[i][j] = '.'; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(vector<vector<char>> &board , int row , int col , char c){

    for(int i = 0 ; i < 9 ; i++){
        if(board[i][col] == c) return false;
        if(board[row][i] == c) return false;
    }

    int boxRowStart = 3 * (row/3);
    int boxColStart = 3 * (col/3);

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(board[boxRowStart + i][boxColStart + j] == c)
                return false;
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
};