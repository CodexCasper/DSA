class Solution {
public:
    int candy(vector<int>& ratings) {
        //TC:O(n) , SC:O(1)
        int n = ratings.size();
        //initially give candies to each child 
        int candies = n;
        //start from second child
        int i = 1;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            int peak = 0;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                candies += peak;
                i++;
            }

            int down = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                down++;
                candies += down;
                i++;
            }

            candies -= min(down ,peak);
        }
        return candies;
    }
};