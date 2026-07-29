class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size()-1;
        //do not take numbers.size() as vector stays 0-indexed only answer will answer will be 1 indexed
        int left = 0;
        int right = n;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum==target){
                return{left+1,right+1};
            } else if (sum > target) {
                right--;
            } else left++;
        }
        return {};
    }
};