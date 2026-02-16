class Solution {
public:

int possible(vector<int> &weights,int capacity){
    int n = weights.size();
    int days = 1 , load = 0;
    for( int i = 0 ; i < n ; i++ ){
        if( load + weights[i] > capacity ){
            days += 1;
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        
        while( low <= high ){
            int mid = (low + high) / 2;
            int value = possible(weights,mid);

            if( value <= days ){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};