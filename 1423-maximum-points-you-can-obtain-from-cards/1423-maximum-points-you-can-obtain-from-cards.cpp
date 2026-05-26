class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //TC:O(2 * k)
        //SC:O(1)
        int leftsum = 0;
        int maxsum = 0;
        int rightsum = 0;
        for(int i = 0 ; i <= k-1 ; i++){
            leftsum += cardPoints[i];
            maxsum = leftsum;
        }
        int rindex = cardPoints.size() - 1;
        for(int i = k - 1 ; i >= 0 ; i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rindex];
            rindex--;
            maxsum = max(maxsum , leftsum + rightsum);
        }
        return maxsum;
    }
};