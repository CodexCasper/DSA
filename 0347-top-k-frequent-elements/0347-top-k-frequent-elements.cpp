class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //TC:O(n + m log k) , worst case m == n   so O(n log k) m is unique elements
        //SC:O(n)
        unordered_map<int , int> freq;
        // element   freq
        // 1      -> 3
        // 2      -> 2
        // 3      -> 1
        for(int num : nums){
            freq[num]++;
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minheap;

        for(auto it : freq){
            // minheap = [(3,1) , (2,2) , (1,3)]  (frequency , element)
            minheap.push({it.second , it.first});
            
            // the moment size inc. more than k plz remove acc to freq
            //when (1,3) will enter minheap will pop coz minheap follows minimum at top and here we used freq. of elements instead of elments itself
            if(minheap.size() > k){
                minheap.pop();
            }
        }

        vector<int> result;
        while(!minheap.empty()){
            result.push_back(minheap.top().second);
            minheap.pop();
        }

        return result;
    }
};