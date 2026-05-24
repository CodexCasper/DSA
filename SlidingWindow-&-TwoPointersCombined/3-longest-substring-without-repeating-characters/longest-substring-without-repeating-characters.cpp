class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //tC:O(n) SC:O(256)
        int n = s.size();

        int HashLen = 256;

        int hash[HashLen];

        for(int i = 0 ; i < HashLen ; i++){
            hash[i] = -1;
        }

        int l = 0 , r = 0 , maxlen = 0;
        while(r < n){
            if(hash[s[r]] != -1){ // found the repeating character
                l = max(hash[s[r]] + 1 , l); 
            }
            int len = r - l + 1;
            maxlen = max(maxlen , r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};