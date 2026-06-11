class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //TC:O(n log n) + O(n)
        //SC:O(1)
        //first we will sort the intervals based on their end time just like n meetings in a room problem
        sort(intervals.begin() , intervals.end() , [](auto& a , auto& b){
            return a[1] < b[1];
        });
        //count the intervals that we will remove
        int cnt = 0;
        
        //store the end of the first interval so that when we iterate we can compare if the next does not overlap
        int prevEnd = intervals[0][1];

        for(int i = 1 ; i < intervals.size() ; i++){
            //if the next interval starting time comes under previous interval ending time that means it is merging and we should remove it
            if(intervals[i][0] < prevEnd){
                cnt++;
            }
            else { // else take that end time as new preious endinng time to compare
                prevEnd = intervals[i][1];
            }
        }
        return cnt;
    }
};