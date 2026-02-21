class Solution {
public:
//TC:O(n) , SC:O(n)
    int romanToInt(string s) {
        int ans = 0;
        
        // map roman numbers with integer value
        unordered_map<char,int> roman = {
            {'I' , 1} , {'V' , 5} , {'X' , 10} , {'L' , 50} , {'C', 100} , {'D', 500} , {'M' , 1000}
        };

        ///traverse the striing
        for( int i = 0 ; i < s.size() - 1; i++ ){

            // concept is only for six numbers 4 ,9 ,40 ,90 , 400 , 900 smaller number comes before the larger otherwise in roman addition of numbers occurs from left to right 
            // i.e -> IV 
            // I < V so ans  = 0 - s[0] => 0 - 1 => -1
            //in last ans = -1 + V => -1 + 5 => 4
            if( roman[s[i]] < roman[s[i+1]] ) ans -= roman[s[i]];
            else ans += roman[s[i]];
        }

        // add the value of the last character bcoz last char. always gets add and there is no need of comparison
        return ans + roman[s.back()];
    }
};