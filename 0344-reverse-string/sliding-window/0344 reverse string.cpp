class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = 0 , k = s.size()-1;
        while( j < k ){
            swap(s[j],s[k]);
            j++;
            k--;
        }
    }
};
