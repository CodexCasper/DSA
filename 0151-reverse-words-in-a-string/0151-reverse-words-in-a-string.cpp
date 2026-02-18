class Solution {
public:
//TC:O(n + n + n) ~ O(n) , SC:(n)
    //function to  the 
    string reverseWords(string s) {
        //vector to store the words 
        vector<string> words;
        
        // Temporay string to store a single word and if space found push to vector
        string word = "";
        
        // traverse the string character by character and temporarlily adding in word string until space found 
        for( int i = 0 ; i < s.size() ; i++ ) {
            if( s[i] != ' ') {
                word += s[i];
            }

        // if space found and we have a word 
            else if( !word.empty() ){

                // then push it in words list
                words.push_back(word);

                //reset word for next word collection
                word = "";
            }
    }
            // loops ends and in the last if there is no space then it will push the last reamining word 
            //i.e. "hello parth" parth is never pushed 
            if( !word.empty() ) {
                words.push_back(word);
            }
            
            // reversing the vector of words 
            // i.e =>  ["i", "am" , "gonna", "make", "it"]
            //becomes=>["it", "make", "gonna", "am", "i"]
            reverse(words.begin(), words.end());
 
            // join the words into a single string with spaces b/w them
            string result = "";

            //traverse 
            for( int i= 0 ; i < words.size(); i++ ){
                result += words[i];
                
                //add spaces if it is not a last word
                if( i < words.size() - 1 ) result += " ";
            }
            return result;
        }
};