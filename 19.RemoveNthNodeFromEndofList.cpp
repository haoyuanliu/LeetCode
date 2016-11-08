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
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            ListNode *p, *pre;
            p = head;
            int len = 0;
            while(p)
            {
                len++;
                p = p->next;
            }
            int count = 0;
            pre = p = head;
            while(p)
            {
                if(count == (len - n))
                {
                    if(pre == p)
                        return head->next;
                    else
                    {
                        pre->next = p->next;
                        return head;
                    }
                }
                count++;
                pre = p;
                p = p->next;
            }
        }
};

int main()
{
    Solution res;
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    int num, temp;
    for(int i = 0; i < 5; ++i)
    {
        cin >> temp;
        p->next = new ListNode(temp);
        p = p->next;
    }
    cin >> num;
    p = res.removeNthFromEnd(head->next, num);
    while(p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}
