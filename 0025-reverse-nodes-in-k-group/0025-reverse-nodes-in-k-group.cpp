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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //if empty
        if(head == NULL){
            return NULL;
        }
        
        //if k nodes remain or less
        ListNode* check = head;
        int count = 0;
        while(check != NULL && count < k){
            check = check -> next;
            count++;
        }
        if(count < k) return head;

        //if k number of nodes remain
        int cnt = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(cnt < k && curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if(next != NULL){
            head -> next = reverseKGroup(next, k); 
        }
        
        return prev;
    }
};