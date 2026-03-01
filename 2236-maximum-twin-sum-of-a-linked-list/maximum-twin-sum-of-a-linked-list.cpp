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
    ListNode* reverseLL(ListNode* temp){ //O(n/2)
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        /*
        //TC:O(n) , SC:O(n)

        //initialize list and convert LL into list
        vector<int> list;

        //push each element into list
        while(head != nullptr){
            list.push_back(head->val);
            head = head->next;
        }

        //use two pointer approach and traverse from both sides and check the condition
        int i = 0;
        int j = list.size() - 1;
        int maxi = 0;

        while(i < j) {
            //storing the current maximum and returning it 
            maxi = max(maxi, list[i]+list[j]);

            i++;
            j--;
        }
    return maxi;
    */

    //TC:O(n/2 + n/2 + n/2) == O(N) , sC:O(1)
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){ // O(n/2)
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* p1 = reverseLL(slow);
    ListNode* p2 = head;
    int maxi = 0;

    while(p1 != nullptr && p2 != nullptr){ // O(n/2)
        maxi = max(maxi, p1->val + p2->val);
        p1 = p1->next;
        p2 = p2->next;
      }
      return maxi;
    }
};