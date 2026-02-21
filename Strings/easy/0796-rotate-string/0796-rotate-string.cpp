class Solution {
public:
//TC:O(N*N) ,SC:O(N)
// substr 1 -> n
// substr 2 -> n
// concat -> n
// compare -> n 
// total -> (4n) = O(n) * O(n) == O(n * n) 
    bool rotateString(string s, string goal) {
        
        // the size of both strings should be equal to compare the rotations 
        if( s.size() != goal.size() ) return false;

        for( int i = 0 ; i < s.size() ; i++ ){
            
            // combining the roated string and checking with goal
            //i.e. i = 0 => abcde + 0
            // i = 1 => bcde + a
            // i = 2 => cde + ab
            // i = 3 => de + abc
            // i = 4 => e + abcd
            string rotated = s.substr(i) + s.substr(0,i);

            if( rotated == goal ) return true;
        }
        return false;
    }
};