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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode* dummy = new ListNode(INT_MAX, list1);

        ListNode* prevHead = dummy;

        while(head1 != NULL && head2!= NULL){
            if(head1 -> val <= head2 -> val){
                prevHead -> next = head1;
                prevHead = head1;
                head1 = head1 -> next;
            }
            else{
                prevHead -> next = head2;
                prevHead = head2;
                head2 = head2 -> next;
            }
        }

        while(head1 != NULL){
            prevHead -> next = head1;
            prevHead = head1;
            head1 = head1 -> next;
        }

        while(head2 != NULL){
            prevHead -> next = head2;
            prevHead = head2;
            head2 = head2 -> next;
        }
        return dummy -> next;
    }
};
