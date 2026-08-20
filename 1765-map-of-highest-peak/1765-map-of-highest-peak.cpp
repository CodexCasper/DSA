class Solution {
public:
vector<int> dr = {-1, 1 , 0 ,0};
vector<int> dc = {0 , 0 , -1 ,1};

bool valid(int row , int col , int n , int m){
    if(row < 0 || col < 0 || row >= n || col >= m)
        return false;
    return true;
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        //tC:O(n * m)
        //SC:O(n * m)
        int n = isWater.size();
        int m = isWater[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> height(n , vector<int>(m , -1));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(isWater[i][j] == 1) {
                    q.push({i,j});
                    height[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;

            for(int k = 0 ; k < 4 ; k++){
                int newrow = row + dr[k];
                int newcol = col + dc[k];

                if(valid(newrow , newcol , n , m) &&
                   height[newrow][newcol] == -1){

                    height[newrow][newcol] = height[row][col] + 1;
                    q.push({ newrow ,newcol });
                   
                   }
            }
        }
        return height;
    }
};