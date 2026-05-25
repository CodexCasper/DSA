class Solution {
public:
    int characterReplacement(string s, int k) {
        //TC:O(N) , SC:O(26)
        vector<int> freq(26,0);

        int maxlen = 0;
        int maxfreq = 0;
        int l = 0 , r = 0;
        
        while(r < s.size()){
            freq[s[r] - 'A']++;

            maxfreq = max(maxfreq , freq[s[r] - 'A']);

            if((r - l + 1) - maxfreq > k){
                freq[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};