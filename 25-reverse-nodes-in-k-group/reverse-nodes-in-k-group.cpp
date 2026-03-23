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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //TC:O(n + m.k)
        int len = 0;
        ListNode* curr = head;

        while(curr != nullptr){
            len++;
            curr = curr->next;
        }
        
        ListNode* dummy = new ListNode(0,head);

        int times = len / k;
        curr = head;

        ListNode* p1 = dummy;
        for(int i = 0 ; i < times ; i++){

            int counter = 0;
            ListNode* prev = NULL;
            ListNode* p2 = curr;

            while(counter < k && curr != nullptr){
                counter++;

                ListNode* next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
            }
            p1->next = prev;
            p2->next = curr;

            p1 = p2;
        }
        return dummy->next;
    }
};