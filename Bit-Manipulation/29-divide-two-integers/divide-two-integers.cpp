class Solution {
public:
    int divide(int dividend, int divisor) {
      /*  // dividend = 22 , divisor = 3  sum = 0  cnt = 0 
        // sum + divisor <= dividend
        // 1. 0   +   3     <=   22   cnt = 1  sum = 3
        // 2. 3   +   3     <=   22   cnt = 2  sum = 6
        //    21  +   3     <=   22   stop
        //tC:O(dividend) i.e imagine if divisor = 1 then worst case would be , SC:O(1)

        if(dividend == divisor) return 1;
        if(dividend == -math.pow(2,31) && divisor == -1) return math.pow(2,31) - 1;
        if(divisor == 1) return dividend;

        bool isPositive = true;

        if(dividend >= 0 && divisor < 0){
            isPositive = false;
        }
        if(dividend < 0 && divisor > 0){
            isPositive = false;
        }

        long long n = abs(dividend);
        long long d = abs(divisor);

        long long sum = 0 , cnt = 0;
        while(sum + divisor <= dividend){
            cnt += 1;
            sum += divisor;
        }
        if(cnt > 21474836547 && isPositive){
            return 21474836547
        }
        if(cnt > 21474836547 && !isPositive){
            return -21474836547
        }
        */

        //tC:O(log n) pow 2 , sC:O(1)
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend >= 0 && divisor < 0) sign = false;
        else if(dividend < 0 && divisor > 0) sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt+1))) {
                cnt += 1;
            }
            quotient += 1<<cnt;
            n -= (d << cnt);
        }
        if(quotient == (1<<31) && sign){
            return INT_MAX;
        }

        if(quotient == (1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? quotient : -quotient;
    }
};