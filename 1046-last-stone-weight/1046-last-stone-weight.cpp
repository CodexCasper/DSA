class Solution {
public:
//TC:O(n log n) , SC:O(n)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;

        for(int stone: stones) {
            maxheap.push(stone);
        }

        while(maxheap.size() > 1) {

            int first = maxheap.top();
            maxheap.pop();

            int second = maxheap.top();
            maxheap.pop();

            if(first != second) {
                maxheap.push(first - second);
            }
        }
        if(maxheap.empty()) {
            return 0;
        }

        return maxheap.top();
    }
};