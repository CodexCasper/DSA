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

    ListNode* mergeTwoSortedLinkedList(ListNode* list1 , ListNode* list2){
        //taking dummynode to handle the first node
        ListNode* dummynode = new ListNode(-1);
        //taking temp also to dummynode to build mergelist and in the end return
        ListNode* temp = dummynode;

       //traverse both lists
        while(list1 != nullptr && list2 != nullptr){
            //choose smaller node
            if( list1->val <= list2->val ){
                //assign it to dummynode for list1
                temp->next = list1;
                //go to next element
                list1 = list1->next;
                
                //if list2 is smaller
            } else{
                temp->next = list2;
                list2 = list2->next;
            }
            //always inc temp after one iteration
            temp = temp->next;
        }
        
        //if any list reamains add it in the  end 
        if(list1 != nullptr){
            temp->next = list1;
        } else{
            temp->next = list2;
        }
        
        //returning dummmynode->next bcoz that is where head exists
        return dummynode->next;
    }

    ListNode* findMiddle(ListNode* head){
        //if only one node then return or 2 nodes then also first will be the head
        if(head == nullptr || head->next == nullptr) return head;
 
        // taking fast one step ahead so that we will get the middle , if we wnt to delete it then fast will be two steps ahead
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        //inc both of them
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //eventually slow will reach at mid
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
    /*    //TC:O(2 * n + n log n) , sC:O(n)
        //taking an addtional array to store the nodes and directly apply sort function , s:O(n)
        vector<int> arr;
        
        // 4 -> 2 -> 1 -> 3 
        //temp
        //[ 4 2 1 3 ]
        // sort [ 1 2 3 4 ]
        // 1 -> 2 -> 3 -> 4


        // using temp to traverse the LL 
        ListNode* temp = head;
        
        //storing the nodes in arr , t: O(n) 
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        //apply sorting function , t :O(n logn)
        sort(arr.begin(), arr.end());
        
        // again take temp to head bcoz to reassign the node from arr to LL
        temp = head;

        //assign , t: O(n)
        for(int i = 0 ; i < arr.size(); i++){
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
        */
        //TC:O(n log n)
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* middle = findMiddle(head);

        //split
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        //again call
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedList(left, right);
    }
};