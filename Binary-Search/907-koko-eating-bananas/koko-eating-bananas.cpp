class Solution {
public:
long long calculatehours ( vector<int> &arr, int hourly ){
    int n = arr.size();
    long long totalh = 0;
    for( int i= 0 ; i < n ; i++ ){
        totalh += (arr[i] + hourly - 1) / hourly;
    }
    return totalh;
}


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = INT_MAX;
        int low = 1,high = *max_element(piles.begin(),piles.end());
        while( low <= high ){
            int mid = ( low + high ) / 2;
            long long totalh = calculatehours(piles,mid);
            if ( totalh <= h ){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};