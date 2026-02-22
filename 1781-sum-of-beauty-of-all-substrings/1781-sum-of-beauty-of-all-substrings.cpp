class Solution {
public:
//TC:O(n) outer loop + O(n) inner loop + O(26) in the worst case == O(n*n*26) == O(n*n) , SC:O(26) == O(1)
    int beautySum(string s) {
        int n  = s.size();
        int sum = 0;

        for(int i = 0 ; i < n ; i++){
            unordered_map<char,int> freq;

            for(int j = i ; j < n ; j++){
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(auto it: freq){
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};