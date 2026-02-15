class Solution {
public:
//TC:O(n*log(max(bloomDay))), SC:O(1)

int possible(vector<int> & arr, int mid , int m , int k){
    int n = arr.size();
    int cnt = 0 , bouqet = 0;
    for( int i = 0 ; i < n ; i++ ){
        if( arr[i] <= mid ) cnt++;
        else{
            bouqet += ( cnt / k);
            cnt = 0;
        }
    }
    bouqet += ( cnt / k );
    return ( bouqet >= m );
}
    int minDays(vector<int>& bloomday, long long m, long long k) {
        int n = bloomday.size();
        if(( m * k ) > n )return -1;
        int low = 1, high = *max_element(bloomday.begin(),bloomday.end());
        int ans = -1;
        while( low <= high ){
            int mid = ( low + high ) / 2;
            if(possible(bloomday,mid,m,k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};