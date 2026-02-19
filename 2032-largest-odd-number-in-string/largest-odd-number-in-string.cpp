class Solution {
public:
    //TC:O(N) , SC:(1)
    string largestOddNumber(string num) {

        //fcinding the last odd digit in the string bcoz we only care about the last digit being odd 
        int index = -1;
        for( int i = num.size() ; i >= 0 ; i-- ){
            if(( num[i] - '0' ) % 2 == 1 ){
                index = i;
                break;
            }
        }
        //for example : "000012345"
        // here we dont wnt our ansswer to include 0 so we start a pointer and minimize the window to return substr for our odd number 
        int i = 0;
        while( i <= index && num[i] == '0' ) i++;
        
        // we know that that index -  i + 1 will return our current od size window 
        return num.substr( i , index - i + 1 );
    }
};