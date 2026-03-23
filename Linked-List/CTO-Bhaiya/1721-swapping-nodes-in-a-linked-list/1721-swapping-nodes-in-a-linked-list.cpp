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
    ListNode* swapNodes(ListNode* head, int k) {
        //TC:O(N) ,S:O(1)
        //intuition is keep first and second at head and move the temp 
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        
        //first find the first node to change and place our first there
        for(int i = 1 ; i < k ; i++){
            first = first->next;
        }
        
        //update the location of temp to first bcoz from there only we need to iterate 
        temp = first;

        //move temp to next while updating second also bcoz when temp->next will reach nullptr then second will be at another element hat need to be replaced
        while(temp->next != nullptr){
            temp = temp->next;
            second = second->next;
        }
        //swap the values 
        int changeVal = first->val;
        first->val = second->val;
        second->val = changeVal;

        return head;
    }
};