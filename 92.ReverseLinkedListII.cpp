#include <iostream>
using namespace std;

class Solution
{
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n)
        {
            if(head == NULL || m == n)
                return head;
            ListNode *root = new ListNode(0);
            root->next = head;
            ListNode *pre, *cur, *left;
            left = root;
            for(int i = 1; i < m; ++i)
                left = left->next;
            pre = left->next;
            cur = pre->next;
            for(int i = 0; i < n - m; ++i)
            {
                pre->next = cur->next;
                cur->next = left->next;
                left->next = cur;
                cur = pre->next;
            }
            return root->next;
        }
};
