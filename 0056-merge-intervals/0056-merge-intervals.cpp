class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //TC:O(n log n) + O(n) , SC:O(n)
        // [[1,3] , [2,6] , [8,10] , [15,18]]

        vector<vector<int>> merged;

        if(intervals.size() == 0){
            return merged;
        }
        
        sort(intervals.begin() , intervals.end());
        
        //temp = [1,3]
        vector<int> temp = intervals[0];
        for(auto it : intervals){
            //it[0] 1 <= temp[1] 3
            if(it[0] <= temp[1]){
                //temp[1] = max(3 , 3) = 3
                temp[1] = max(it[1] , temp[1]);
            }
            else{
                merged.push_back(temp);
                temp = it;
            }
        }
        merged.push_back(temp);
        return merged;
    }
};