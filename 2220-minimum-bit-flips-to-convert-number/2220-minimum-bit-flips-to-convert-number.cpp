class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*
        //TC:O(31) , brute force
        int ans = start ^ goal; //taking xor operator will flip the bit indexes needed to flip
        //and we will count them using below operation
        int cnt = 0;
        for(int i = 0 ; i < 32 ; i++){ // taken 31 bcoz it is mentioned that it is an integer
        //we know this is how we check if the i bit is set or not
            if(ans & (1 << i)) cnt += 1;
        }
        return cnt;
        */
        //TC:O(logn(start ^ goal)) bcoz we do not need to go upto 31 if it is only 4 bits, SC:O(1)
        int ans = start ^ goal; // doing the same xor operator tp find out min bits
        int cnt = 0;
        while(ans > 1){
           // if(ans % 2 == 1) cnt += 1;
           // ans /= 2;
           cnt += ans & 1;  // we replaced , bcoz taking (&) of ans and 1 will be same as we know it is working for odd and if we take and the (&) thn also the last bit will be set bit
           ans >>= 1; // formula for right shift
        }
        if( ans == 1) cnt += 1;
        return cnt;
    }
};