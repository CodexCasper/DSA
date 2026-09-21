class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a , b;

        for(char ch: s) {

            if(ch != '#') {
                a.push_back(ch);
            }
            else if(!a.empty()) {
                a.pop_back();
            }
        }
        for(char ch: t) {

            if(ch != '#') {
                b.push_back(ch);
            }
            else if(!b.empty()) {
                b.pop_back();
            }
        }

        return a == b;
    }
};