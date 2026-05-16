class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();
        vector<int> st;

        for(int i = 0; i < n; i++) {
            int currEle = asteroids[i];

            // positive asteroid
            if(currEle > 0) {
                st.push_back(currEle);
            }
            // negative asteroid
            else {
                while(!st.empty() && st.back() > 0 && st.back() < abs(currEle)) {
                    st.pop_back();
                }

                // equal collision
                if(!st.empty() &&
                   st.back() == abs(currEle)) {
                    st.pop_back();
                }
                // current negative survives
                else if(st.empty() || st.back() < 0) {
                    st.push_back(currEle);
                }
            }
        }
        return st;
    }
};