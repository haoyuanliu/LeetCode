/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *temp;
        pre->next = NULL;
        while(cur->next)
        {
        	temp = cur->next;
        	cur->next = pre;
        	pre = cur;
        	cur = temp;
        }
        cur->next = pre;
        return cur;
    }
};


class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *res;
        ListNode *p, *q;
        p = head->next;
        while(p->next)
        {
            q = p->next;
            p->next = q->next;
            q->next = head->next;
            head->next = q;
        }
        p->next = head;
        res = head->next;
        head->next = NULL;
        return res;
    }
};
