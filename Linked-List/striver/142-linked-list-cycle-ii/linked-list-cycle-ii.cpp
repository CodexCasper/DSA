class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if cycle exists
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                break;
            }
        }

        // No cycle
        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }

        // Step 2: Find cycle start
        ListNode* n1 = slow;
        ListNode* n2 = head;

        while(n1 != n2){
            n1 = n1->next;
            n2 = n2->next;
        }

        return n1;
    }
};