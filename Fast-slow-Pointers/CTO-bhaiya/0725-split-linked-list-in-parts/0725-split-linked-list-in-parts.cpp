class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //T:O(n) , S:O(k)
        //steps:
        //1. distribution strategy of numbers like if k = 3 then how it is divides
        //2.then how to convert into seperate linked list
        int len = 0;
        ListNode* curr = head;
        
        //first we calculated the len so that we divide it by k to find unifrom distribution
        while(curr != nullptr){
            len += 1;
            curr = curr->next;
        }
        
        // if k = 3 and len = 10 then ans = 3 , uniform
        int uniformdistribution = len / k;
        //if k = 3 and len = 10 then ans = 1 , extra to add at the front
        int remainingDigitNumber = len % k;
        
        //our new answer ll
        vector<ListNode*> res(k);   // FIX
       
        //take back surr to head
        curr = head;
        
        //  1 2 3 4 5 6 7 8 9 10
        //curr
        //temp
        //prev
        for(int i = 0; i < k ; i++){
            int count = uniformdistribution;

            if(remainingDigitNumber > 0){
                count += 1;
                remainingDigitNumber -= 1;
            }

            res[i] = curr;   // store head of part

            ListNode* temp = curr;
            int counter = 0;
            ListNode* prev = NULL;

            while(counter < count && curr != nullptr){
                prev = curr;
                curr = curr->next;
                counter += 1;
            }

            if(prev != nullptr){
                prev->next = nullptr;
            }
        }

        return res;
    }
};