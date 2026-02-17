class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     /*   //TC:O(n*m), SC:O(1) 
          int n = matrix.size();
          int m = matrix[0].size();
          for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == target) return true;
            }
            return false;
          }
*/
        
        //TC:O(log(n*m)), SC:O(1)

// A 2-D matrix stored row-wise behaves like a 1-D array if we see it from left -> right row by row 
// and mid refers to the index in an array but we need for matrix so we must convert it
// index: 0 1 2 3 4 5   6  7  8
// value: 1 3 5 7 9 11 13 15 17
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = (n*m) - 1;
        while( low <= high ){
            int mid = ( low + high ) / 2;

            int row = mid / m; // if we observe then we can see that each row has "m" elements which tells which row block mid belongs to
            int col = mid % m; // and after finding the row we need to find position inside that, remainder tells that 

            if(matrix[row][col] == target) return true;
            else if( matrix[row][col] < target ) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};