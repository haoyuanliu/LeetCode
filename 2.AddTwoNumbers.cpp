/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        int carry = 0;
        int a, b, c;
        while(l1 || l2)
        {
            a = b = c = 0;
            if(l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            c = a + b + carry;
            p->next = new ListNode(c % 10);
            carry = c / 10;
            p = p->next;
        }
        if(carry == 1)
        {
            p->next = new ListNode(1);
        }
        return head->next;
    }
};

## Unaccpted
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    ListNode *zero = new ListNode(0);
    ListNode *res = new ListNode(-1);
    ListNode *p = res;
    int carry = 0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(l1 && l2)
        {
            int temp = l1->val + l2->val + carry;
            p->next = new ListNode(temp % 10);
            carry = temp / 10;
            p = p->next;
        }
        if(l1) p->next = addTwoNumbers(l1, zero);
        if(l2) p->next = addTwoNumbers(l2, zero);
        if(carry == 1)
        {
            p->next = new ListNode(1);
        }
        return res->next;
    }
};
