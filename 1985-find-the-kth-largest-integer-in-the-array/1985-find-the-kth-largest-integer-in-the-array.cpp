class cmp {
public:
    bool operator()(string &a, string &b) {
        if(a.size() != b.size())
            return a.size() > b.size();

        return a > b;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string , vector<string> ,cmp> minheap;

        for(int j = 0 ; j < nums.size() ; j++) {
            minheap.push(nums[j]);

            if(minheap.size() > k){
                minheap.pop();
            }
        }
        return minheap.top();
    }
};