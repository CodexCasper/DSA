class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //TC:O(log k * n) , bcoz size of heap is log n and log k bcoz we only keep k elements and for total (n) pushes it is O(n*log k)
        //SC:O(k) bcoz size never exceeds k
        int n = nums.size();
        //priority queue is maxheap bydefault ,  we need to define minheap diff
        priority_queue<int , vector<int> , greater<int>> minheap;
        
        //approach
        //1.simply only push k size elements
        //2.and if size exceeds k then pop the smallest 
        //3.bcoz minheap keep the minimum at root and pop means taking out root element
        //4.and when the root element pops out then next minimum reaches at root and again pop out
        for(int i = 0 ; i < n ; i++){
            minheap.push(nums[i]);

            if(minheap.size() > k){
                minheap.pop();
            }
        }
        return minheap.top();
    }
};