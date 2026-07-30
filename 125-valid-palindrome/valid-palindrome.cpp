class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0 ; i < s.size() ; i++){
            s[i] = tolower(s[i]);
        }
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(s[left] == s[right]){
                left++;
                right--;
            }
            else return false;  
        }
        return true;
    }
};