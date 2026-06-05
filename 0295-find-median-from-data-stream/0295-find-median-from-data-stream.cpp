class MedianFinder {
private:
priority_queue<int> maxheap;
priority_queue<int , vector<int> , greater<int>> minheap;    
public:
//TC:O(N log N+ M) bcoz each call to addnum takes O(Log N) for 'N' numbers and for findMedian it takes O(1)
//SC:O(N)
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //maxheap = 1
        maxheap.push(num);
        
        //minheap = 1
        //maxheap = empty
        minheap.push(maxheap.top());
        maxheap.pop();
        
        //min size == 1 > max size = 0
        if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()){
            return(maxheap.top() + minheap.top()) / 2.0;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */