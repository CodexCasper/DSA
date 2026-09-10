class Solution {
public:
//TC:O(n + m log m + n log m) + SC:O(n + m)
    string reorganizeString(string s) {
        unordered_map<char,int> mpp;

        for(char ch: s) {
            mpp[ch]++;
        }

        priority_queue<pair<int,char>> maxheap;

        for(auto it: mpp) {
            maxheap.push({it.second , it.first});
        }

        string res = "";
        int seat = 0;

        while(!maxheap.empty()) {
            pair<int , char> p1 = maxheap.top();
            maxheap.pop();

            if(seat == 0 || res[seat - 1] != p1.second) {

                res.push_back(p1.second);
                seat++;
                p1.first--;

                if(p1.first > 0) {
                    maxheap.push(p1);
                } 
            }
            else {
                if(maxheap.empty()) {
                    return "";
                }

                pair<int,char> p2 = maxheap.top();
                maxheap.pop();

                res.push_back(p2.second);
                seat++;
                p2.first--;

                if(p2.first > 0) {
                    maxheap.push(p2);
                }

                maxheap.push(p1);
            }
        }
        return res;
    }
};