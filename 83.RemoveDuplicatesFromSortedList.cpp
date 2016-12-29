#include <iostream>
using namespace std;

class Solution
{
    public:
        ListNode *deleteDuplicates(ListNode *head)
        {
            if(head == NULL)
                return head;
            ListNode * root = new ListNode(0);
            root->next = head;
            ListNode *pre = root;
            ListNode *cur = head;
            while(cur)
            {
                while(cur->next && cur->next->val == cur->val)
                    cur = cur->next;
                pre->next = cur;
                pre = pre->next;
                cur = cur->next;
            }
            return root->next;
        }
};
