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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int noOfNodes = 0;
        int initialGroupSize = 1;

        ListNode* curr = head;

        while(curr != nullptr){
            noOfNodes++;
            curr = curr->next;
        }

        curr = head;

        ListNode* save1 = NULL;

        while(curr != nullptr){
            int actualGroupSize = min(initialGroupSize , noOfNodes);

            if(actualGroupSize % 2 == 0){
                ListNode* prev = NULL;
                int counter = 0;
                ListNode* save2 = curr;
                while(counter < actualGroupSize){
                    counter++;

                    ListNode* next = curr->next;

                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                save1->next = prev;
                save2->next = curr;

                save1 = save2;
            }
            else{
                int counter = 0;

                while(counter < actualGroupSize){
                    counter++;
                    save1 = curr;
                    curr = curr->next;
                }
            }
            initialGroupSize++;
            noOfNodes -= actualGroupSize;
        }
        return head;
    }
};