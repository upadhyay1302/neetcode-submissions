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
            head = head -> next;
            len ++;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head -> next == NULL) return NULL;
        int len = getLength(head);

        int newK = len - n + 1;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(INT_MAX, curr);
        ListNode* prev = dummy;
        for(int i = 1; i < newK; i++){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        return dummy -> next;
    }
};
