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
    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL) return head;

        int len = getLength(head);

        if(len < k) return head;

        int position = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(position < k){
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            position++;
        }

        if(curr != NULL){
            ListNode* newHead = reverseKGroup(curr, k);
            head -> next = newHead;
        }
        return prev;


    }
};
