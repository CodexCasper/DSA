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
//N = total number of nodes across all k linked lists
//k = number of linked lists
//TC:O(k logk + n logk) only inserting first ele in pq so let them k logk
//SC:O(k)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> minheap;

        for(int i = 0 ; i < lists.size(); i++) {

            if(lists[i] != NULL) {

                minheap.push({lists[i] -> val , lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!minheap.empty()) {

            pair<int,ListNode*> p = minheap.top();
            minheap.pop();

            ListNode* node = p.second;

            tail -> next = node;
            tail = tail -> next;

            if(node->next != NULL) {
                
                minheap.push({node -> next -> val , node -> next});
            }
        }
        return dummy -> next;
    }
};