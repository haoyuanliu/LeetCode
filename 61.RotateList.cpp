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
        ListNode* rotateRight(ListNode *head, int k)
        {
            if(head == NULL)
                return NULL;
            ListNode *res;
            ListNode *p = head;
            int len = 1;
            while(p->next)
            {
                len++;
                p = p->next;
            }

            k %= len;
            if(k == 0)
                return head;
            
            p->next = head;
            while(p)
            {
                p = p->next;
                len--;
                if(len == k)
                {
                    res = p->next;
                    p->next = NULL;
                    break;
                }
            }
            return res;
        }
};

int main()
{
    return 0;
}
