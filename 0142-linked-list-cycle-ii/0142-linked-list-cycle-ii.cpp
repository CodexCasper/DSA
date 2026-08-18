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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast ->next->next;
            
            if(fast == slow) {
                break;
            }
        }
        if(fast == nullptr || fast -> next == nullptr){
            return nullptr;
        }
        ListNode* n1 = slow; // or fast
        ListNode* n2 = head;
        while(n1 != n2){
            n1 = n1 -> next;
            n2 = n2 -> next;
        }
        return n1;
    }
};