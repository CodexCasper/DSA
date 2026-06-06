class Solution {
public:
    bool checkValidString(string s) {
        //tC:O(n) , SC:O(1)
        int minrange = 0;
        int maxrange = 0;

        for(char c : s){
            if( c == '('){
                minrange++;
                maxrange++;
            }
            else if(c == ')'){
                minrange--;
                maxrange--;
            }
            else{
                minrange--;
                maxrange++;
            }
            minrange = max(minrange , 0);
            if(maxrange < 0) return false;
        }
        return(minrange == 0);
    }
};