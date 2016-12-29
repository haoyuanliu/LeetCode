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
        ListNode *deleteDuplicates(ListNode* head)
        {
            if(head == NULL)
                return head;
            ListNode *root = new ListNode((1<<31));
            root->next = head;
            ListNode *cur = head;
            ListNode *pre = root;
            while(cur)
            {
                while(cur->next && cur->val == cur->next->val)
                    cur = cur->next;
                if(pre->next == cur)
                    pre = pre->next;
                else
                    pre->next = cur->next;
                cur = cur->next;
            }
            return root->next;
        }
};

int main()
{
    return 0;
}
