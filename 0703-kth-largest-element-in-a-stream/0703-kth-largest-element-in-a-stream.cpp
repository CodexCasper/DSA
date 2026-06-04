class KthLargest {
priority_queue<int , vector<int> , greater<int>> minheap;
int size;    
public:
    KthLargest(int k, vector<int>& nums) {
        //TC:O((n+m) log k ) m for add function to add m elements , sC:O(k)
        size = k;
        //      2
        //  4      5
        //8
        for(int score : nums){
            minheap.push(score);
            
            //    4
            //5      8
            if(minheap.size() > k){
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        
        if(minheap.size() > size){
            minheap.pop();
        }

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */