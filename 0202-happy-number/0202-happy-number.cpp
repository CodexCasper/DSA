class Solution {
public:
    
    int sumOfDigit(int n){
        int sum = 0;

        while(n > 0){
            int dig = n % 10;
            sum += (dig * dig);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n , fast = n;

        while(fast != 1){
            slow = sumOfDigit(slow);
            fast = sumOfDigit(sumOfDigit(fast));

            if(fast == 1) return true;
            if(slow == fast) return false;
        }
        return true;
    }
};