class Solution {
public:
vector<int> dr = {-1 , 1 , 0 , 0};
vector<int> dc = {0 , 0 , -1 , 1};

bool valid(int row , int col , int n , int m){
    if(row < 0 || col < 0 || row >= n || col >= m){
        return false;
    }
    return true;
}
void dfs(vector<vector<int>>& image, int row, int col, int color,int originalcolor,vector<vector<int>>& result,vector<vector<bool>>& vis){
//tC:O(n * m)
///SC:O(n * m)
    vis[row][col] = true;
    result[row][col] = color;
    int n = image.size();
    int m = image[0].size();
    for(int k = 0 ; k < 4 ; k++){
        int newrow = row + dr[k];
        int newcol = col + dc[k];

        if(valid(newrow , newcol , n , m) &&
        image[newrow][newcol] == originalcolor &&
        !vis[newrow][newcol] ){
            dfs(image , newrow, newcol , color,originalcolor,result , vis);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> result = image;
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        int originalcolor = image[sr][sc];
        if(image[sr][sc] == color) 
            return image;

                if(!vis[sr][sc]) {
                    dfs(image , sr , sc ,color, originalcolor, result , vis);
                }
        return result;
    }
};