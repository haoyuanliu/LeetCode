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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode *even = new ListNode(0);
        ListNode *odd = new ListNode(1);
        ListNode *cur = head;
        ListNode *temp = head;
        ListNode *e = even;
        ListNode *o = odd;
        while(cur)
        {
        	temp = cur->next;
        	o->next = cur;
        	cur->next = NULL;
        	o = o->next;
        	cur = temp;

        	if(cur)
        	{
        		temp = cur->next;
        		e->next = cur;
        		cur->next = NULL;
        		e = e->next;
        		cur = temp;
        	}
        }
        o->next = even->next;
        return odd->next;
    }
};


//Solution II
class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        	return head;
        ListNode *odd =  head;
        ListNode *even = head->next;
        ListNode *evenStart = even;
        while(even && even->next)
        {
        	odd->next = odd->next->next;
        	even->next = even->next->next;
        	odd = odd->next;
        	even = even->next;
        }
        odd->next = evenStart;
        return head;
    }
};