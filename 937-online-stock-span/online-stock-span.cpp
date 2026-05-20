class StockSpanner {
private: 
    stack<pair<int,int>> st;
    int ind;
public:
//TC:O(2N) , SC:O(N) 
    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind = ind + 1; // the first day will be counted bcoz of "=" so if i = 7 then 7 <= 7 bcoz no one is behind 7
        while(!st.empty() && st.top().first <= price){
            st.pop(); // logic of PGE
        }
        int ans;
        if(st.empty()) ans = ind + 1;
        else ans = ind - st.top().second;
        st.push({price,ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */