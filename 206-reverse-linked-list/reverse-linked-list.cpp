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
    ListNode* reverseList(ListNode* head) {
        /*
        //A straightforward approach to reversing a singly linked list is to use an additional data structure such as a stack. As we traverse the list, we push each node’s value onto the stack. Since stacks follow Last-In-First-Out (LIFO) order, popping elements from the stack gives us the values in reverse order. After the stack is filled, we reassign the values to the nodes while traversing the original list again. This effectively reverses the list in terms of values without modifying node links.
        //TC:O(n) , SC:O(n)
        //using stack bcoz it follows LIFO 
        stack<int> st;
        
        //defining a temp bcoz we should temper head and to traverse LL
        ListNode* temp = head;

        //traverse and push all values to stack , O(n)
        while(temp != nullptr){
            st.push(temp->val);
            temp = temp->next;
        }
        
        //after that set temp back to head and store the value from top from stack
        temp = head;

        // re-assign values from stack in reverse order , O(n) reassign in ll
        while(temp != nullptr){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        
        // return the head of LL
        return head;
        */
 
         //TC:O(n) , SC:O(1)
        //intialize previous pointer to null to link the value from starting to end
        ListNode* prev = NULL;

        //starrting from the head of the list
        ListNode* temp = head;

        //while temp is not pointing to nullptr
        while(temp != nullptr){
            
            //  1 -> 2 -> 3 -> NULL
            //prev
            //  temp
            //      front
            //save the next node
            ListNode* front = temp->next;
            
            //reverse the current node pointer , 1->NULL , 2->1->NULL , 3->2->1->NULL
            temp->next = prev;
            
            //move prev to the current node
            prev = temp;
            
            //move to the next node 
            temp = front;
        }
        //return new head(last node becomes first)
        return prev;
    }
};