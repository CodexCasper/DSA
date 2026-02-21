class Solution {
public:
//TC::O( 2 * n) expand once for odd and once for even * O(n) cost of each expansion == O(N*N) , SC:O(1)
    string longestPalindrome(string s) {
        int n = s.size();
        if( n <= 1 ) return s;

        //so we define the maxlen = 1 bcoz atleast 1 will be the palindrome if n = 1
        int start = 0 , maxlen = 1;

        for( int i = 0 ; i < n ; i++ ){
            
            // odd length palindrome 
            //we are at i and we expand through left and right and check 
            int left = i , right = i;

            // must check left and right so that it does not cross out of bound 
            while( left >= 0 && right < n && s[left] == s[right] ){

                // if current length is greater then previous maxlen then update
                if(right - left + 1 > maxlen){
                start = left;
                maxlen = right - left + 1;
                }
                left--;
                right++;
            }
            
            //even length palindrome 
            left = i;
            right = i + 1;
            while( left >= 0 && right < n && s[left] == s[right] ){
                if(right - left + 1 > maxlen){
                    start = left;
                    maxlen = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxlen);
    }
};