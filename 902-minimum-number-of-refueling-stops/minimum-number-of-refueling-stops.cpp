class Solution {
public:
//TC:O(n) + (n logn) + O(n logn) + O(k logn) let fuel < target run k times
//SC:O(n)
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        vector<pair<int,int>> station;

        for(int i = 0 ; i < n ; i++) {

            station.push_back({stations[i][0] , stations[i][1]});
        }
        sort(station.begin() , station.end());

        int stop = 0;
        int fuel = startFuel;
        int idx = 0;
        priority_queue<int> maxheap;

        while(fuel < target) {
            
            while(idx < n) {

                if(station[idx].first > fuel) break;

                maxheap.push(station[idx].second);
                idx++;
            }
            if(maxheap.empty()) return -1;

            fuel += maxheap.top();
            maxheap.pop();
            
            stop++;
        }
        return stop;
    }
};