#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists)
        {
            int len = lists.size();
            if(len == 0)
                return NULL;
            else if(len == 1)
                return lists[0];
            else if(len == 2)
                return mergeTwoLists(lists[0], lists[1]);
            vector<ListNode*> left(lists.begin(), lists.begin() + len/2);
            vector<ListNode*> right(lists.begin()+len/2, lists.end());
            return mergeTwoLists(mergeKLists(left), mergeKLists(right));
        }

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
    return 0;
}
