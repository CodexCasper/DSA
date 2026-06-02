class compare{
public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //TC:O(n * log k) n is the total no. of nodes across all k linked lists and each operation on minheap takes log k time 
        //SC:O(k) heap stores at most k nodes 
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        //head 1->4->5
        //head 1->3->4
        //head 2->6
        // Push heads of all non-empty lists
        for(auto list : lists){
            if(list != NULL){
                pq.push(list); // 1 -> 1 -> 2
            }
        }
        //dummy->0
        ListNode* dummy = new ListNode(0);
        //dummy , tail -> 0
        ListNode* tail = dummy;

        while(!pq.empty()){
            //minheap so [1]
            ListNode* smallest = pq.top();
            //now minheap is 1 -> 2
            pq.pop();
            
            //0 -> 1
            tail->next = smallest;
            //0 -> 1
            //     tail
            tail = tail->next;
            
            //1 -> 1-> 2
            //smallest(list1) which is 1 -> 4 -> 5 , not pointing to  NULL
            if(smallest->next != NULL){
                //1 -> 2 -> 4 
                pq.push(smallest->next);
            }
        }
        
        return dummy->next;
    }
};