class Solution {
public:
void dfs(string &num , int target , int start , long long current_value , long long last_operand , string expression , vector<string> &result){
    // dry run step
    // exammple ->
    // dfs("123", 6 ,start= 0 ,current_value= 0, last_operand= 0 , "");

    //base case
    if(start == num.size()){
        //when start == 3 (end of "123")
        //check if expression value == target
        if(current_value == target){
            result.push_back(expression);
            return;
        }
    }
    //try all substrings from current position
    for(int i = start ; i < num.size() ; i++){

        //dry run 
        //start = 0 -> i= 0 -> current_num = "1";
        //start = 1 -> i= 1 -> current_num = "12";
        //start = 2 -> i= 2 -> current_num = "123";
        if(i > start && num[start] == '0') return;

        string current_num = num.substr(start , i - start + 1);
        long long current_num_val = stoll(current_num);

        //it1:
        //current_num = "1"
        //current_num_val = 1

        if(start == 0){
            //first number -> no operator

            // call ->
            //dfs("123" ,6 , start= 1, 1 , 1 , "1", result)
            dfs(num , target , i + 1 , current_num_val , current_num_val, current_num , result);
        }
        else{
            dfs(num , target , i + 1 , current_value + current_num_val , current_num_val,expression + "+" + current_num , result);

            dfs(num , target , i + 1 , current_value - current_num_val , -current_num_val , expression +"-" +current_num , result);

            dfs(num , target , i + 1 , current_value - last_operand + last_operand * current_num_val ,last_operand * current_num_val, expression+ "*" + current_num, result);
        }
    }
}
    vector<string> addOperators(string num, int target) {
        //to store final result
        vector<string> result;
        //start DFS with empty expression 
        dfs(num , target , 0 , 0 , 0 , "" , result);
        return result;
    }
};