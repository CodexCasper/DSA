class Solution {
public:

    bool isValid(string s) {
        // TC: O(N)
        // SC: O(N) stack space 
        stack<char> st;
        for(auto it : s) {
            if(it == '(' || it == '{' || it == '[') {
                st.push(it);
            }
            else {
                // closing bracket but stack empty means this also will be false 
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();

                if ((it == ')' && ch == '(') ||
                    (it == ']' && ch == '[') ||
                    (it == '}' && ch == '{')) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};