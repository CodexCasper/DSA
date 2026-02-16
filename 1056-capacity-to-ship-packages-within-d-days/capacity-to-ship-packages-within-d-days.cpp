class Solution {
public:

    int possible(vector<int> &arr, int capacity){
        int load = 0, days = 1;
        for( int i = 0 ; i < arr.size() ; i++ ){
            if( load + arr[i] > capacity ){
                days++;
                load = arr[i];
            }
            else load += arr[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;

        while( low <= high ){
            int mid = ( low + high ) / 2;

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