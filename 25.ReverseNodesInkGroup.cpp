#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            int len = getLen(head);
            if(len < k || k == 1)
                return head;
            ListNode *root = new ListNode(-1);
            ListNode *p = root;
            ListNode *p1 = head;
            ListNode *p2 = head;
            while(len >= k)
            {
                for(int i = 0; i < k; ++i)
                {
                    p2 = p1->next;
                    p1->next = p->next;
                    p->next = p1;
                    p1 = p2;
                }
                while(p->next)
                    p = p->next;
                len -= k;
                if(len < k)
                {
                    p->next = p1;
                    return root->next;
                }
            }
            return root->next;
        }
        int getLen(ListNode *head)
        {
            ListNode *p = head;
            int count = 0;
            while(p)
            {
                count++;
                p = p->next;
            }
            return count;
        }
};

