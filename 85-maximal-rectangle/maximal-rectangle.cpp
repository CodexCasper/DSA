class Solution {
public:
int largestRectangleArea(vector<int> &heights){
    stack<int> st;
    int n = heights.size();
    int maxArea = 0;
    heights.push_back(0); // if heights = [1,2,3,4] then nobody gets popped so add '0' at end 
    //[1,2,3,4,0]
    for(int i = 0 ; i <= n ; i++){
        while(!st.empty() && (heights[st.top()] > heights[i])){
            int height = heights[st.top()];
            st.pop();

            int width;
            if(st.empty()){
                width = i;
            }else{
                width = i - st.top() - 1;
            }
            maxArea = max(maxArea , width*height);
        }
        st.push(i);
    }
    return maxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> height(m , 0);

        int maxArea = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(area , maxArea);
        }
        return maxArea;
    }
};