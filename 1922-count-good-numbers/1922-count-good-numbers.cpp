class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long base, long long exp){
        long long ans = 1;

        while(exp){
            if(exp % 2)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};