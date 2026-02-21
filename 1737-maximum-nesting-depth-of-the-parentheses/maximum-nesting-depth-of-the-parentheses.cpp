class Solution {
public:
//TC:O(n) , SC:O(1)
    int maxDepth(string s) {
        int level = 0;
        int ans = 0;
        for( char x : s ){
            if( x == '(') level++; 
            else if( x == ')' ) level--;
            ans = max(level,ans);
        }
        return ans;
    }
};