class Solution {
public:
    int maximumSum(vector<int>& arr) {
        //tC:O(n) , SC:O(1)
        //nodelete is basically bestending and we took it as arr[0] bcoz there are no elements behind arr[0] , now we took onedelete as 'INT_MIN' bcoz we can't delete first element
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        
        //result will be first element just from the start
        int result = arr[0];

        for(int i = 1 ; i < arr.size() ; i++){

            //store nodelete and ondelete in seperate variables 
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;

            //two posibilities if nodelete -> 1.add the curr element in it 2. take only that element
            nodelete = max(nodelete + arr[i] , arr[i]);
            int v2;

            //now we must check if prevonedelete is still INT_MIN so we must take first element which is deleted
            if(prevonedelete == INT_MIN){
                v2 = arr[i];
                
                //or we must add curr element in prevonedelete element
            } else v2 = prevonedelete + arr[i];

            // just take max
            onedelete = max(v2 , prevnodelete);

            result = max(result , max(onedelete , nodelete));
        }
        return result;
    }
};