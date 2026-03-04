class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //TC:O(n) , SC:O(1)
        ///always take node where we see that head of the linked list is in danger or may be it can be removed 
        //if dummy node will not be there then we have to seperately check the edge case 
        //i.e. if( head->val == val) head = head->next;
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;

        while (temp->next != nullptr) {

            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } 
            else {
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};