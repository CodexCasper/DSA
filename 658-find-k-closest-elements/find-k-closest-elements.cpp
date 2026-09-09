class Solution {
public:
//TC:O(n log k) + O(k log k) + O(k log k) , SC:O(k) + O(k)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       
        priority_queue<pair<int,int>> maxheap;

        for(int i = 0 ; i < arr.size() ;i++) {

            int diff = abs(arr[i] - x);

            maxheap.push({ diff , arr[i]});

            if(maxheap.size() > k) {
                // is arr is nor sorted 
                /*f(maxheap.top().first == diff &&
                   maxheap.top().second > arr[i]) {

                    maxheap.pop();
                    maxheap.push({diff, arr[i]});
                }
                else {
                    maxheap.pop();
                }*/
                maxheap.pop();
            }
        }
        vector<int> ans;
        while(!maxheap.empty()) {
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};