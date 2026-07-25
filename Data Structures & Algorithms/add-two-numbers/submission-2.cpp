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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode(-1);
        ListNode* ans = curr;

        int carry = 0;

        while(l1 || l2){
            int digit1 = l1 ? l1 -> val : 0;
            int digit2 = l2 ? l2 -> val : 0;

            int digitSum = digit1 + digit2 + carry;

            if(digitSum > 9){
                digitSum = digitSum - 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode* newDigit = new ListNode(digitSum);
            curr -> next = newDigit;
            curr = curr -> next;

            if(l1 != NULL) l1 = l1 -> next;
            if(l2 != NULL) l2 = l2 -> next;

        }
        if(carry){
            ListNode* newDigit = new ListNode(carry);
            curr -> next = newDigit;
        }
        return ans -> next;
    }
};
