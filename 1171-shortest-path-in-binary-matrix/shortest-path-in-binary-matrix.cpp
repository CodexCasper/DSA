class Solution {
public:
//tC:(n * n) , SC:O(n * n)
vector<int> dr = {-1 , 1 , 0 , 0 , 1 , -1 , 1 , -1};
vector<int> dc = {0 , 0 , -1 , 1 , 1 , 1 , -1 , -1};

bool valid(int row , int col , int n , int m){
    if(row < 0 || col < 0 || row >= n || col >= m){
        return false;
    }
    return true;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        vector<vector<int>> visited(n , vector<int>(n , 0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0} , 1});
        visited[0][0] = 1;

        while(!q.empty()) {

            pair<pair<int,int>,int> p = q.front();
            q.pop();

            int row = p.first.first;
            int col = p.first.second;
            int length = p.second;

            if(row == n-1 && col == n-1){
                return length;
            }

            for(int k = 0 ; k < 8 ; k++) {
                int newrow = row + dr[k];
                int newcol = col + dc[k];

                if(valid(newrow , newcol , n , n) && 
                   grid[newrow][newcol] == 0 &&
                   !visited[newrow][newcol]
                   ) {

                   visited[newrow][newcol] = 1;
                   q.push({{newrow,newcol} , length + 1});
                   }
            }
        }
        return -1;
    }
};