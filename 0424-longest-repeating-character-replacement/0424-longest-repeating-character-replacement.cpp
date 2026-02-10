class Solution {
public:
    int characterReplacement(string s, int k) {
        /*int n = s.size();
        int ans = 0;

        TC:O(n*n), SC:O(26 == 1)
        for(int i = 0 ; i < n ; i++){

            unordered_map<char,int> freq;
            int maxfreq = 0;

            for(int j = i ; j < n ; j++){
                freq[s[j]]++;
                maxfreq = max(maxfreq, freq[s[j]]);

                int stringLength = j - i + 1;
                int counting = stringLength - maxfreq;

                if(counting <= k) ans = max(ans,stringLength);
                else break;
            }
        }
        return ans;
        */
        int n = s.size();
        int ans = 0;
        int left = 0, right = 0;
        int maxfreq = 0;

        unordered_map<char,int> freq;

        while( right < n ){

            freq[s[right]]++;

            maxfreq = max(maxfreq,freq[s[right]]);

            while( (( right - left + 1) - maxfreq) > k ) {
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};