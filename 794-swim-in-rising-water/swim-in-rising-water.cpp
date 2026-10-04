class Solution {
public:
//TC:O(n * n log (n * n)) , SC:O(2 * n * m)
vector<int> dr = {-1 , 1 , 0, 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row ,int col , int n , int m) {
    if(row < 0 || col < 0 || row >= n || col >= m) {
        return false;
    }
    return true;
}
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();

        priority_queue<pair<int, pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0] , {0,0}});

        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));
        dist[0][0] = grid[0][0];

        while(!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int time = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(time > dist[row][col]) continue;

            if(row == n-1 && col == n-1) return time;

            for(int k = 0 ; k < 4 ; k++) {
                int newrow = row + dr[k];
                int newcol = col + dc[k];

                if(!valid(newrow , newcol , n ,n)) continue;

                int newTime = max(time , grid[newrow][newcol]);

                if(newTime < dist[newrow][newcol]) {
                    dist[newrow][newcol] = newTime;
                    pq.push({newTime , {newrow , newcol}});
                }
            }
        }
        return -1;
    }
};