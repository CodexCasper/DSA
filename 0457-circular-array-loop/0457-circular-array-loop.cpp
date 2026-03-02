class Solution {
public:
    // Helper function to calculate next index
    int calcNextIdx(vector<int>& nums, int curr) {
        int n = nums.size();
        int next = (curr + nums[curr]) % n;

        // Handle negative modulo properly
        if (next < 0)
            next += n;

        return next;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        //TC:L(n*n) , SC:O(n)
        //applying brute force approach and checking for every index if it makes cycle with conditions
        for(int i = 0 ; i < n ; i++){

            // using set to quickly check if we have visited the element previously
            unordered_set<int> visited;

            //inserting the elements in set
            visited.insert(i);

            //acc. to condition we must check if all elements are +ve or -ve in cycle 
            bool isPos = nums[i] > 0;

            //also using current to calculate next element 
            int current = i;

            while(true){

                //helper functionn which will calculate next element
                int next = calcNextIdx(nums , current);
 
                //if isPos is true then check next if next is -ve then break and check next index
                if(isPos){
                    if(nums[next] < 0) break;

                    //if first element is -ve but next index is +ve then break and check next element
                    } else {
                        if(nums[next] > 0) break;
                    }

                    //check if already viviyed the set -> then possible cycle is there 
                    if(visited.count(next)){
                        
                        //if k>1 then no self loop , if there is only 1 element then both current and next 
                        //will point to same index and if not then k > 1 condtion satisfies
                        if(current != next) return true;
                        else break;
                    }
                    //insert the index in set
                    visited.insert(next);

                    //update current to next
                    current = next;
            }
        }
        return false;
    }
};