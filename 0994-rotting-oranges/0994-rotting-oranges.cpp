class Solution {
public:
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};
bool valid(int row , int col , int n , int m) {
    if(row < 0 || col < 0 || row >= n || col >= m) 
       return false;
    return true;   
}
    int orangesRotting(vector<vector<int>>& grid) {
        //TC:O(n * m)
        //SC:O(n * m)
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++) {
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = -1;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh > 0) {
            time++;
            int s = q.size();

            while(s--) {
                pair<int,int> rottenorange = q.front();
                q.pop();
                int row = rottenorange.first;
                int col = rottenorange.second;

                for(int k = 0 ; k < 4 ; k++){
                    int newrow = row + dr[k];
                    int newcol = col + dc[k];

                    if(valid(newrow , newcol , n , m) &&
                       grid[newrow][newcol] == 1) {

                        q.push({newrow , newcol});
                        grid[newrow][newcol] = -1;
                        fresh--;
                       }
                }
            }
        }
        if(fresh > 0) return -1;
        return time;
    }
};