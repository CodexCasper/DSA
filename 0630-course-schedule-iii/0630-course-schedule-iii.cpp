class Solution {
public:
//TC:O(n logn) , SC:O(n)
static bool cmp(vector<int> &a , vector<int> &b) {

    return a[1] < b[1];
}
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end() , cmp);

        priority_queue<int> maxheap;
        int time = 0;

        for(auto course: courses) {

            int duration = course[0];
            int deadline = course[1];

            time += duration;
            maxheap.push(duration);

            if(time > deadline) {

                time -= maxheap.top();
                maxheap.pop();
            }
        }
        return maxheap.size();
    }
};