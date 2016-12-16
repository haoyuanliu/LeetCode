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
        ListNode *insertionSortList(ListNode *head)
        {
            if(head == NULL)
                return head;
            ListNode *root = new ListNode(0);
            root->next = head;
            ListNode *p = root;
            ListNode *pre = root;
            ListNode *tail = head;
            ListNode *cur = head;
            while(tail->next)
            {
                cur = tail->next;
                p = root->next;
                pre = root;
                while(p->val < cur->val && p != tail->next)
                {
                    pre = p;
                    p = p->next;
                }
                if(p == tail->next)
                {
                    tail = tail->next;
                    continue;
                }
                pre->next = cur;
                tail->next = cur->next;
                cur->next = p;
            }
            return root->next;
        }
};

class Solution
{
    public:
        ListNode *insertionSortList(ListNode *head)
        {
            if(head == NULL)
                return head;
            ListNode *root = new ListNode(0);
            ListNode *pre = root;
            ListNode *cur = head;
            ListNode *next = NULL;
            while(cur)
            {
                next = cur->next;
                while(pre->next && pre->next->val < cur->val)
                    pre = pre->next;
                cur->next = pre->next;
                pre->next = cur;

                cur = next;
                pre = root;
            }
            return root->next;
        }
};


int main()
{
    return 0;
}
