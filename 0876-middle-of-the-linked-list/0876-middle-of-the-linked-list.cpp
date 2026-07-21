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
    int getLen(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head -> next;
        }
        return cnt;
    }

public:
    ListNode* middleNode(ListNode* head) {

        if(head == NULL || head-> next == NULL){
            return head;
        }

        ListNode* fast = head -> next;
        ListNode* slow = head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
        }
        return slow;
        // int n = getLen(head);
        // int middle = (n/2);
        // ListNode* temp = head;
        // int c = 0;
        // while(c < middle){
        //     temp = temp -> next;
        //     c++;
        // }
        // return temp;
    }
};