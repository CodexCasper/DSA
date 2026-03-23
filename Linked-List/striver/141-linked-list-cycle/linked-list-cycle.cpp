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
//k -> node before cycle starts 
//c -> cycle length 
// slow must walk k steps to reach hte cycle -> O(k)
// inside cycle fast->2 steps slow->1 step so fast gains 1 step per iteration on slow, worst case fast needs at most c step to catch slow -> O(c)
//TC:O(k+c) == O(n) , SC:O(1)
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;       
        }
        return false;
    }
};