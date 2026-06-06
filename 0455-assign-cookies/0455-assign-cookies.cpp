class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //TC:O(n logn + m logm)
        //SC:O(1)
        int n = g.size();
        int m = s.size();
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int l = 0 , r = 0;
        // g = 1 2 3  n
        //     r
        // s = 1 1    m
        //     l
        while( l < m && r < n){
            if(g[r] <= s[l]){
                r = r + 1;
            }
            l = l + 1;
        }
        return r;
    }
};