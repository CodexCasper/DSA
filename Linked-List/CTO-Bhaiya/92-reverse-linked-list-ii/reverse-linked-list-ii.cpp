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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //T:O(n) , S:O(1)
       ListNode* dummy = new ListNode(0,head);
       ListNode* prev = dummy;

        for(int i = 1 ; i < left ; i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;

        for(int i = 0 ; i < right - left ; i++){
            ListNode* next = curr->next;
            
            // dummy -> 1 -> 2 -> 4 -> 5 , 3 is temporaily removed
            //              prev curr 
            curr->next = next->next;
            // 3 -> 2  , -> 4 -> 5
            next->next = prev->next;
            // 1 -> 3  , -> 2 -> 4 -> 5
            prev->next = next;

        }
        return dummy->next;
    }
}; // this is called Head Insertion inside a sublist

//First, find the node just before the position left. This node (prev) will help reconnect the reversed section with the rest of the list.

//The node at position left becomes curr, which will stay at the end of the reversed section during the process.

//Now repeatedly take the node after curr (next) and move it right after prev.

//Each time you move next, the sublist grows in reverse order at the front.

//After doing this right - left times, the required part of the list becomes reversed.
