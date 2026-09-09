class Solution {
public:
//TC:O(m log k) + O(k log k) + O(k log k) , sc:(k)
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<int,int>> maxheap;

        for(int i = 0; i < mat.size(); i++) {

            int soldiers = 0;

            for(int j = 0; j < mat[i].size(); j++) {

                if(mat[i][j] == 1)
                    soldiers++;
            }

            maxheap.push({soldiers, i});

            if(maxheap.size() > k)
                maxheap.pop();
        }

        vector<int> ans;

        while(!maxheap.empty()) {

            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};