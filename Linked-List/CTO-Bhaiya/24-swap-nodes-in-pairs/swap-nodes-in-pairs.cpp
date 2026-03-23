/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //tC:O(n) , sC:O(1)
        //taking so that it can handle the head case , if i.e 1 -> 2 -> 3 -> 4 then 
        ListNode* dummy = new ListNode(0,head);

        // dummy -> 1 -> 2 -> 3 -> 4
        //curr1
        //prev
        //taking curr1 at head and prev at dummy to create links since we need to directly modify the nodes
        ListNode* curr1 = head;
        ListNode* prev = dummy;

        // dummy -> 1 -> 2 -> 3 -> 4
        // prev   curr1 curr2
        //it1  dummy -> 2 -> 1 -> 3 -> 4
        //                  prev curr1 curr2
        //it2  dummy -> 2 -> 1 -> 4 -> 3
        //                        prev   curr1
        //we can see the while condition for even is curr != next after that no need to run
        //for odd dummy -> 1 -> 2 -> 3
        //         prev  curr1 curr2
        ///it1    dummy -> 2 -> 1 -> 3
        //                     prev curr1
        //so in odd until curr2 != nullptr we  need to  check
        while(curr1 != nullptr && curr1->next != nullptr){
            ListNode* curr2 = curr1->next;
            //prev -> 2
            prev->next = curr2;
            //prev-> 1 -> 3;
            //taken thi step before the afterward step to save the next of 3
            curr1->next = curr2->next;
            //prev -> 2 -> 1 -> 3
            curr2->next = curr1;

            prev = curr1;
            curr1 = curr1->next;

        }
        return dummy->next;
    }
};