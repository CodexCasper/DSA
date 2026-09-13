class Solution {
public:
//TC:O(n logn + k logn) , SC:O(n)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<pair<int,pair<int,int>> ,
                      vector<pair<int,pair<int,int>>>,
                      greater<pair<int,pair<int,int>>>
                      > minheap;

        int n = matrix.size();
        for(int i = 0 ; i < n ; i++) {

            minheap.push({matrix[i][0] , {i , 0}});
        }

        int ans = 0;
        while(k--) {

            pair<int , pair<int,int>> p = minheap.top();
            minheap.pop();

            ans = p.first;

            int row = p.second.first;
            int col = p.second.second;

            if(col + 1 < n) {

                minheap.push({
                    matrix[row][col+1] , {row , col + 1}
                });
            }
        }   
        return ans;           
    }
};