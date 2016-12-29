#include <iostream>
using namespace std;

class Solution
{
    public:
        ListNode* partition(ListNode* head, int x)
        {
            if(head == NULL || head->next == NULL)
                return head;
            ListNode *left = new ListNode(0);
            ListNode *right = new ListNode(0);
            ListNode *l = left;
            ListNode *r = right;
            ListNode *p = head;
            while(p)
            {
                if(p->val < x)
                {
                    l->next = p;
                    l = l->next;
                }
                else
                {
                    r->next = p;
                    r = r->next;
                }
                p = p->next;
            }
            r->next = NULL;
            l->next = right->next;
            return left->next;
        }
};