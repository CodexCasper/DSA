class Solution {
public:
    //TC:O(n) , SC:O(n) bcoz rhe ecusion stack goes upto n 

    int helper(const string &s , int i , long long num , int sign){
        // check first if we are out of bounds or at non-digit return
        //if are at the end of our string or the no. is not number then return current builded number 
        if( i >= s.size() || !isdigit(s[i])) 
            return (int)(sign*num);

        // update num with current digit
        // num == 0 currently ans acc to ASCII we have '0' = 48 it cconverts every substring to number 
        // " -043" so '4' - '0' = 52 - 48 == 4
        num = num * 10 + (s[i] - '0');

        //overflow condition
        if(sign * num <= INT_MIN) return INT_MIN;
        if(sign * num >= INT_MAX) return INT_MAX;

        //recursive for next character
        return helper(s , i+1 , num, sign);
    }

    int myAtoi(string s, int i = 0) {

        //skip leading whitespaces ans also check whether index i is within the valid bounds of the string 
        //" -042" so i will ignore ' '
        //  i
        while( i < s.size() && s[i] == ' ') i++;

        //handle sign
        //again check whether index i is within the valid bounds of the string
        // "  -0455"
        //     i   assign sign = -1 bcoz s[i] is '-'
        int sign = 1;
        if( i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // call recusive helper , o is current num builder 
        return helper(s , i , 0 , sign);
    }
};