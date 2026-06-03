class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //TC:O(n logk)
        //SC:O(K)
        //map to store the freq. of every element
        unordered_map<char , int> freq;
        for(char task: tasks){
            freq[task]++;
        }

        priority_queue<int> maxheap;
        //use of "&" is simply giving reference to the original values of char insteead of creating a copy 
        for(auto & entry : freq){
            maxheap.push(entry.second);
        }
        //total time required to execute
        int time = 0;
        //until maxheap is not empty , bcoz we immediately pushed the temp values to heap after pooping in inner while loop
        while(!maxheap.empty()){
            //set no of task allowed in the cycle
            int cycle = n + 1;
            //counter to track how many task we ran in the cycle 
            int i = 0;
            //to store the remaining freq of the char
            vector<int> temp;
            while(i < cycle && !maxheap.empty()){
                //get the most frequent remaining tasks
                int cnt = maxheap.top();
                maxheap.pop();

                //reduce its freq as we are runnin it once 
                cnt--;
                
                // If the task still has pending frequency, store it for later
                if(cnt > 0) temp.push_back(cnt);

                time++;
                // Move to next slot in the cycle
                i++;
            }
            //Push leftover tasks of this cycle back into the heap
            for (int val : temp) {
                maxheap.push(val);
            }

            //If heap is empty, no need to count idle time
            if (maxheap.empty()) break;

            //Add idle time to complete the cycle (if any slots were left)
            time += (cycle - i);
        }
        return time;
    }
};