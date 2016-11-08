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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
        {
            ListNode* head = new ListNode(0);
            ListNode* p = head;
            while(l1 && l2)
            {
                if(l1->val > l2->val)
                {
                    p->next = new ListNode(l2->val);
                    p = p->next;
                    l2 = l2->next;
                }
                else
                {
                    p->next = new ListNode(l1->val);
                    p = p->next;
                    l1 = l1->next;
                }
            }
            if(l1)
                p->next = l1;
            if(l2)
                p->next = l2;

            return head->next;
        }
};

int main()
{
    Solution res;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    ListNode* p;
    int temp;
    p = l1;
    for(int i = 0; i < 5; ++i)
    {
        cin >> temp;
        p->next = new ListNode(temp);
        p = p->next;
    }

    p = l2;
    for(int i = 0; i < 5; ++i)
    {
        cin >> temp;
        p->next = new ListNode(temp);
        p = p->next;
    }

    p = res.mergeTwoLists(l1->next, l2->next);
    while(p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
