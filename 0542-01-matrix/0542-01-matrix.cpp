class Solution {
public:
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};
bool valid(int row , int col , int n , int m) {
    if(row < 0 || col < 0 || row >= n || col >= m) 
        return false;
    
    return true;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //TC:O(n * m)
        //SC:O(n * m)
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n , vector<int>(m , -1));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(mat[i][j] == 0) {
                    q.push({i , j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){

            pair<int,int> p = q.front();
            q.pop();

            int row = p.first;
            int col = p.second;
            for(int k = 0 ; k < 4 ; k++){

                int newrow = row + dr[k];
                int newcol = col + dc[k];

                if(valid(newrow,newcol,n,m) &&
                   dist[newrow][newcol] == -1){

                    dist[newrow][newcol] = dist[row][col] + 1;
                    q.push({newrow , newcol});
                   }
            }
        }
        return dist;
    }
};