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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr -> next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        //O(n) space complexity ---------------------------------------------
        /*ListNode* temp = head;
        vector<int> arr;

        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int s = 0;
        int e = arr.size()-1;
        while(s <= e){
            if(arr[s] != arr[e]) return false;
            s++;
            e--;
        }
        return true;*/
        //---------------------------------------------------------------------

        if(head == NULL || head-> next == NULL){
            return true;
        }
        ListNode* middle = getMid(head);
        ListNode* temp = middle-> next;
        middle -> next = reverse(temp);

        //comparing the 2
        ListNode* head1 = head;
        ListNode* head2 = middle-> next;

        while(head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        temp = middle-> next;
        middle -> next = reverse(temp);

        return true;
    }
};