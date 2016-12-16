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
        ListNode *sortList(ListNode *head)
        {
            if(!head || !head->next)
                return head;
            ListNode *p = head;
            ListNode *p2 = head;
            while(p && p2->next->next)
            {
                p = p->next;
                p2 = p2->next->next;
                if(p2->next == NULL)
                    break;
            }
            ListNode *head2 = p->next;
            p->next = NULL;
            return merge(sortList(head), sortList(head2));
        }

        ListNode *merge(ListNode *a, ListNode *b)
        {
            ListNode *root = new ListNode(1);
            ListNode *p = root;
            while(a && b)
            {
                if(a->val > b->val)
                {
                    p->next = b;
                    b = b->next;
                    p = p->next;
                    p->next = NULL;
                }
                else
                {
                    p->next = a;
                    a = a->next;
                    p = p->next;
                    p->next = NULL;
                }
            }
            if(a)
                p->next = a;
            if(b)
                p->next = b;
            return root->next;
        }
};
int main()
{
    return 0;
}
