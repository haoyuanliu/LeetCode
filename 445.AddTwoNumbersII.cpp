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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    	bool f1 = false;
    	bool f2 = false;
    	vector<int> sum;
        ListNode *res = new ListNode(0);
        ListNode *p = l1;
        ListNode *q = l2;
        while(p && q)
        {
        	if(f1 || f2)
        	{
        		int temp = (f1 ? p->val : 0) + (f2 ? q->val : 0);
        		sum.push_back(temp);
        	}
        	p = p->next;
        	q = q->next;
        	if(f1 && f2 && p == q)
        		break;
        	if(p == NULL)
        	{
        		p = l2;
        		f1 = true;
        	}
        	if(q == NULL)
        	{
        		q = l1;
        		f2 = true;
        	}
        }
        int carry = 0;
        for(int i = sum.size()-1; i >= 0; --i)
        {
        	sum[i] = sum[i] + carry;
        	carry = sum[i] / 10;
        	sum[i] %= 10;
        }
        if(carry)
        	sum.insert(sum.begin(), carry);

        ListNode *cur = res;
        for(int i = 0; i < sum.size(); ++i)
        {
        	cur->next = new ListNode(sum[i]);
        	cur = cur->next;
        }
        return res->next;
    }
};

//Solution II
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> f1, f2;
        ListNode *res = new ListNode(0);
        int sum  = 0;
        while(l1)
        {
        	f1.push(l1->val);
        	l1 = l1->next;
        }
        while(l2)
        {
        	f2.push(l2->val);
        	l2 = l2->next;
        }

        while(!f1.empty() || !f2.empty())
        {
            if(!f1.empty()){sum+=f1.top();f1.pop();}
            if(!f2.empty()){sum+=f2.top();f2.pop();}
            res->val = sum % 10;
            ListNode* head = new ListNode(sum /= 10);
            head->next = res;
            res = head;
        }
        return res->val? res : res->next;
    }
};