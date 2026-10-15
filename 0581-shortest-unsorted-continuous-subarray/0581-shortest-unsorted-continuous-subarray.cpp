class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());

        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left < n && nums[left] == temp[left]) {
            left++;
        }
        while(right >= 0 && nums[right] == temp[right]) {
            right--;
        }

        if(left >= right) return 0;
        return right - left + 1;
        */
        int left = -1;
        int right = -1;
        int maxi = INT_MIN , mini = INT_MAX;

        for(int i = 0 ; i < nums.size() ; i++) {

            if(nums[i] < maxi){
                right = i;
            }
            maxi = max(maxi , nums[i]);
        }

        for(int i = nums.size() - 1 ; i >= 0 ; i--) {

            if(nums[i] > mini) {
                left = i;
            }
            mini = min(mini , nums[i]);
        }
        if(right == -1) return 0;
        
        return right - left + 1;
    }
};