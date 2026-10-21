class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        /* TC:O(3 * n) , SC:O(2 * n)
        vector<int> prefixsum(n);
        vector<int> suffixsum(n);

        prefixsum[0] = height[0];
        for(int i = 1 ; i < n ; i++) {
            prefixsum[i] = max(prefixsum[i - 1] , height[i]);
        }

        suffixsum[n-1] = height[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            suffixsum[i] = max(suffixsum[i+1] , height[i]);
        }

        int totalwater = 0;
        
        for(int i = 0 ; i < n ; i++) {
            int leftmax = prefixsum[i];
            int rightmax = suffixsum[i];

            int water = min(leftmax,rightmax) - height[i];
            totalwater += water;
            
        }
        return totalwater;
        
        //TC:O(2 * n) , SC:O(n)
        
        vector<int> suffixmax(n);
        suffixmax[n-1] = height[n-1];
        for(int i = n-2 ; i >= 0 ; i--) {
            suffixmax[i] = max(suffixmax[i+1] , height[i]);
        }

        int leftmax = 0 , rightmax = 0, totalwater = 0;
        for(int i = 0 ; i < n ; i++) {
            leftmax = max(leftmax , height[i]);
            rightmax = suffixmax[i];

            int water = min(leftmax , rightmax) - height[i];
            totalwater += water;
        }
        return totalwater;
        */
        int left = 0 , right = n - 1;
        int leftmax = 0 , rightmax = 0;

        int totalwater = 0;
        while(left <= right) {

            if(height[left] <= height[right]) {

                if(height[left] >= leftmax){
                    leftmax = height[left];
                }
                else {
                    totalwater += leftmax - height[left];
                }
                left++;
            }
            else {
                if(height[right] >= rightmax) {
                    rightmax = height[right];
                }
                else {
                    totalwater += rightmax - height[right];
                }
                right--;
            }
        }
        return totalwater;
    }
};