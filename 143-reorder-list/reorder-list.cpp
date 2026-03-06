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
    void reorderList(ListNode* head) {
        // 1 -> 2 -> 3 -> 4 -> 5
        //1 -> 5 -> 2 -> 4 -> 3

        //using fast and slow pointer approach to find midddle so that we can reverse from middle to end, so that it becomes list and then we can stitch
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 1 -> 2 -> 3 -> 4 -> 5
        //          slow       fast
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

       //reverse from slow to tail
       // 1 -> 2 , 5 -> 4 -> 3
        ListNode* temp = NULL;
        ListNode* curr = slow;
        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = temp;
            temp = curr;
            curr = next;
        }
        
        // 1- > 2
        //l1
        // 5 -> 4 -> 3
        //l2
        ListNode* l1 = head;
        ListNode* l2 = temp;

        // 1 - > 2
        //l1     storageofl1
        // 5 -> 4 -> 3
        //l2   storageofl2
        //storing the next values of l1 and l2 so that when we will change the next values then others values which is next of it should not be lost
        while( l2->next != nullptr){
            ListNode* storageOfL1 = l1->next;
            l1->next = l2;

            ListNode* storageOfL2 = l2->next;
            l2->next = storageOfL1;

            l1 = storageOfL1;
            l2 = storageOfL2;
        }
    }
};