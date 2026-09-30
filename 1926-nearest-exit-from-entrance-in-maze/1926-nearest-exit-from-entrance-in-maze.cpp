class Solution {
public:
//TC:O(n * m) , SC:O(n * m)
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {
    if(row < 0 || col < 0 || row >= n || col >= m) {
        return false;
    }
    return true;
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        
        int r = entrance[0];
        int c = entrance[1];

        q.push({r, c});
        maze[r][c] = '+';

        int dist = 0;

        while(!q.empty()) {

            int s = q.size();
            dist++;

            while(s--) {

                pair<int,int> p = q.front();
                q.pop();

                int row = p.first;
                int col = p.second;

                for(int k = 0 ; k < 4 ; k++) {
                    int newrow = row + dr[k];
                    int newcol = col + dc[k];

                    if(valid(newrow , newcol , n , m) && maze[newrow][newcol] == '.'){

                        if(newrow == 0 || newrow == n-1 || newcol == 0 || newcol == m -1) {
                        return dist;
                    }

                    maze[newrow][newcol] = '+';
                    q.push({newrow , newcol});
                    }
                }
            }
        }
        return -1;
    }
};