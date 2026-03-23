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
    ListNode* deleteMiddle(ListNode* head) {
/*
        //tC:O(n + n/2) , sC:O(1)
        //initialize a temp variable to traverse the linked list
        ListNode* temp = head;

        //first count the no. of nodes in llto find out middle
        int cnt = 0;

        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        
        //it will give the middle node 
        int rem = n / 2;
        //reset temp to hea to traverse upto n/2 so delete the middle node 
        temp = head;

        while(temp != NULL){
            //subtracting the no of nodes to reach just before the middle 
            rem--;

            if(rem == 0){
                //first make a new node to middle
                ListNode* middle = temp->next;
                //skip the middle node
                temp->next = temp->next->next;
                //free it
                free(middle);

                break;
            }
            temp =  temp->next;
        }
        return head;
        */

        //TC:O(n/2) ,sC:O(1)
        //if the list has only one node delete it
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        
        //we take fast two steps further slow so that speed b/w them becomes constant and slow will reach exactly one point before middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        //traverse until fast reaches end 
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //point our slow to next of middle and skip the middle
        prev->next = slow->next;

        return head;
    }
};