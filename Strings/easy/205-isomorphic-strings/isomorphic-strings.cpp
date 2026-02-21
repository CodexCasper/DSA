class Solution {
public:
//TC:O(N), SC:O(1)
// intuition for the qn is => two strings are isomorphic if every chaaracter appears at the same previous index in both strings
//i =>  0 1 0 3 4
// s =  p a p e r
// t =  t i t l e
    bool isIsomorphic(string s, string t) {
        //it creates an arr of 256 integers bcoz char are stored as ASCII codes and then we initialiazed every element to 0 
        int m1[256] = {0}, m2[256] = {0};

        // get the length of the strings 
        int n = s.size();

        // traverse each character of the string
        for( int i = 0 ; i < n ; i++ ){
            
            // if previous positions of current character differ then return false 
            if( m1[s[i]] != m2[t[i]] ) return false;

            //update the position with the current index 
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        // if no mismatch is found return true 
        return true;
    }
};