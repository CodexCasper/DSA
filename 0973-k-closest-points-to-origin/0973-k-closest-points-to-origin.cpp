class Solution {
public:
//TC:O(n log k) , SC:O(k)
int distance(vector<int>& points) {

    int x = points[0];
    int y = points[1];

    return x * x + y * y;
}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxheap;

        for(int i = 0 ; i < points.size() ; i++) {

            int dist = distance(points[i]);

            maxheap.push({dist , points[i]});

            if(maxheap.size() > k) maxheap.pop();;
        }

        vector<vector<int>> ans;
        while(!maxheap.empty()) {
            ans.push_back({maxheap.top().second});
            maxheap.pop();;
        }
        return ans;
    }
};