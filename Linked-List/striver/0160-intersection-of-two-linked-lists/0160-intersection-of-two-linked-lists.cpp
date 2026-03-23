/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//tC:O(n+m) n and m length of l1 and l2 , SC:O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //traversing from both heads of given linkedlist
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        
        // traverse both lists and if any of them reaches end then  redirect it to the head of other list
        while(d1 != d2){
            // first '=' is being assigned and second '==' is being checked
            //if it is null then point to other list head or do ++
            d1 = d1 == NULL ? headB : d1->next;
            d2 = d2 == NULL ? headA : d2->next;
        }
        //if they meet return the intersection node otherwise null
        return d1;
    }
};