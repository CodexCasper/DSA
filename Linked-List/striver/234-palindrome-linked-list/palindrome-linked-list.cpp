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
    ListNode* reverseLL(ListNode* curr) {
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
    
    bool isPalindrome(ListNode* head) {
        /*
        //TC:O(n) , SC:O(n)

        //converting our linked list to list so that we can random access,use pointers
        vector<int> list;
        
        //storing in list using head
        while(head != nullptr){
            list.push_back(head->val);
            head = head->next;
        }

        //using two ptr approach two compare from start and back side for palindrome
        int i = 0;
        int j = list.size() - 1;
        while(i < j){
            if(list[i] != list[j]) return false;

            i++;
            j--;
        }
        return true;
        */
        ListNode* slow = head;
        ListNode* fast = head;
        //tc:O(n), sC:O(1)
        //4 -> 3 -> 3 -> 4
        //h
        //          s      
        //                 f
        //p1
        // 4 -> 3
        // p2
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* p1 = reverseLL(slow);
        ListNode* p2 = head;

        while(p1 != nullptr && p2 != nullptr){
            if(p1->val != p2->val) return false;

            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};