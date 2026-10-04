class Solution {
public:
//tc:O(n * m log(n *m)) , SC:O(2 * n * m)
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m) {

    if(row < 0 || col < 0 || row >= n || col >= m) {
        return false;
    }
    return true;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> res(n , vector<int>(m , INT_MAX));
        res[0][0] = 0;

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0 , {0,0}});

        while(!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int dist = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(dist > res[row][col]) continue;

            for(int k = 0 ; k < 4 ; k++) {
                int newrow = row + dr[k];
                int newcol = col + dc[k];

                if(!valid(newrow , newcol , n , m)) continue;

                int absDiff = abs(heights[row][col] - heights[newrow][newcol]);

                int newWT = max(absDiff , dist);

                if(newWT < res[newrow][newcol]) {

                    res[newrow][newcol] = newWT;
                    pq.push({newWT , {newrow,newcol}});
                }
            }
        }
        return res[n-1][m-1];
    }
};