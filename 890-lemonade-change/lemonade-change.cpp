class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //TC:O(n) , SC:O(1)
        int n = bills.size();
        int five = 0 , ten = 0;

        for(int i = 0 ; i < n ; i++){
            if(bills[i] == 5){
                five += 1;
            }
            else if(bills[i] == 10){
                if(five > 0){
                    five -= 1;
                    ten += 1;
                } else return false;
            }
            else{ // 20
                if(five > 0 && ten > 0){
                    five--;
                    ten--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};