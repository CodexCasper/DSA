class Solution {
public:
// anagram means one is permutaton of another , also it means that same letters with same count order doesn't matter
//intuition -> add letters from one string and delete from another string in the same frequency arr. if freq. arr becomes 0 then they are anagrams
    bool isAnagram(string s, string t) {
  /*     // TC:O( 1 + n log n + n ) == O(n) , SC:O(1)
        // checking whether both strings are of same size, if not then what is the meaning of searching forward
        if( s.size() != t.size() ) return false;  // O(1)
        
        //sorting both strings 
        sort( s.begin(), s.end() );    // costs ( n log n ) + ( n log n )
        sort( t.begin(), t.end() );

        //just check if any element of strings is diff. then it can not be the anagram of each other 
        for( int i = 0 ; i <  s.size() ; i++ ){
            if( s[i] != t[i] ) return false;
        }
        return true;
        */
//TC:O(N) , SC:O(1)
        if(s.size() != t.size()) return false;

        // arr to count freq 
        // index 0 -> count of A
        // index 1 -> count of B
        int freq[256] = {0};

        // adding all the elments of s string 
        for( int i = 0 ; i < s.size() ; i++ ){

            // here we convert letter into index 
            //'A' - 'A' = 0
            //'B' - 'B' = 1
            //'C' - 'C' = 2
            freq[s[i]]++;
        }
        //Decremrnt the freq. for each char in t string 
        for( int i = 0 ; i < t.size() ; i++ ){
            freq[t[i]]--;
        }

        // now check if freq is 0 then no extra elment found and hence anagram
        for(int i = 0 ; i < 256 ; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};