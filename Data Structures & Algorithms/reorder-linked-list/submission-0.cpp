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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL){
            fast = fast ->next -> next;

            slow = slow -> next;
        }

        ListNode* curr = slow;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* forward = curr -> next;
            curr ->next = prev;
            prev = curr;
            curr = forward;
        }

        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l2 -> next != NULL){
            ListNode* l1N = l1 ->next;
            l1 -> next = l2;

            ListNode* l2N = l2 -> next;
            l2 -> next = l1N;

            l1 = l1N;
            l2 = l2N;
        }
    }
};