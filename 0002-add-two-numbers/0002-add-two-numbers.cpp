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
private:
    void insertAtTail(ListNode* &sumHead, ListNode* &sumTail, int digit){
        ListNode* temp = new ListNode(digit);
        if(sumHead == NULL){
            sumHead = temp;
            sumTail = temp;
            return;
        }
        sumTail -> next = temp;
        sumTail = temp;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumHead = NULL;
        ListNode* sumTail = NULL;
        int carry = 0;

        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            int digit = sum % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            int digit = sum % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = sum / 10;
            l1 = l1->next;      // fixed — advance l1
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            int digit = sum % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = sum / 10;
            l2 = l2->next;      // fixed — advance l2
        }
        while(carry != 0){
            int digit = carry % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = carry / 10;
        }
        return sumHead;
    }
};