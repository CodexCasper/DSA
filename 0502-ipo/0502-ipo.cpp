class Solution {
public:
//TC:O(n) + o(n logn) + O(n logn) + O(k llgon) , SC:O(n)
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int,int>> project;
        for(int i = 0 ; i < n ; i++) {

            project.push_back({capital[i] , profits[i]});
        }

        sort(project.begin() , project.end());

        priority_queue<int> maxheap;
        int idx = 0;

        while(k--) {
            while(idx < n) {
            
            if(project[idx].first > w) break;

            maxheap.push(project[idx].second);
            idx++;
            }
        //edge case
        if(maxheap.empty()) break;

        w += maxheap.top();
        maxheap.pop();
        }
        return w;
    }
};