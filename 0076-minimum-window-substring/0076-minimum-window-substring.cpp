class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);

        for(char ch : t){
            hash[ch]++;
        }
        int l = 0 , r = 0;
        int startingIndex = -1;
        int minLen = INT_MAX;
        int cnt = 0;

        while(r < s.size()){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;

            while(cnt == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    startingIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(startingIndex == -1){
            return "";
        }
        return s.substr(startingIndex , minLen);
    }
};