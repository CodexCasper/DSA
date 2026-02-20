class Solution {
public:
//TC:O(N) , SC:O(1)
    string removeOuterParentheses(string s) {
        
       // initialize a empty string to add inside parentheses 
       string result = "";

       // intialize nesting level counter
       int level = 0;

       // traveerse the string 
       for(char ch : s){

        //if we see '(' , then inc the lvel
        if( ch == '(' ){

            // if we inside a primitve, add a '(' to result
            if( level > 0 ) result += ch;
            
            //inc the nesting level
            level++;
        }
        //If we encounter ')', decrease the level
        else if( ch == ')' ){

            // Decrease the nesting level for ')'
            level--;

            if( level > 0 ) result += ch;
            }
       }
       return result; 
    }
};