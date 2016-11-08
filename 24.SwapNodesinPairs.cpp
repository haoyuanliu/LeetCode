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
        ListNode* swapPairs(ListNode* head)
        {
            if(!head->next)
                return head;
            ListNode* root = new ListNode(0);
            root->next = head;
            ListNode *p, *c;
            p = root;
            c = root->next->next;
            while(c)
            {
                p->next->next = c->next;
                c->next = p->next;
                p->next = c;
                p = p->next->next;
                if(p->next)
                    c = p->next->next;
                else
                    break;
            }
            return root->next;
        }
};
