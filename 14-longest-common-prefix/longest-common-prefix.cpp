class Solution {
public:
//TC:O( N log N + M) , SC:O(M) , m = min. length of string 
    string longestCommonPrefix(vector<string>& strs) {
        //if string is empty from the start then return empty string
        if( strs.empty() ) return "";

        // performing sorting lexicographically so that it will be easy for us to compare only the first and the last string 
        // ie.["flower", "flow" , "flight"] => ["flight","flow","flower"]
        sort( strs.begin(), strs.end() );

        // first = flight , last = flower 
        string first = strs[0];
        string last = strs[strs.size() - 1];

        //empty string to store our answer
        string ans = "";

        //this will make sure that we should not traverse invalid memory bcoz
        // i.e if first = flow and last = flower then it will traverse beyond first 
        int minlength = min(first.size(),last.size());

        //comapre the characters of first and last string 
        for( int i = 0 ; i < minlength ; i++ ){
            if( first[i] != last[i] ) break;

            ans += first[i];
        }

        //second way using substring
/*      int i = 0; 
        while(i<minlength && first[i] == last[i]) i++;
        return strs.substr( 0 , i);
*/
        // return the longest common prefix 
        return ans;
    }
};