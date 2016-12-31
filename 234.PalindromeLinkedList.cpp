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
    bool isPalindrome(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *pre = slow->next;
        ListNode *cur = pre->next;
        slow->next = NULL;
        pre->next = NULL;
        
        while(cur)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        ListNode *p = head;
        
        while(pre && p)
        {
            if(pre->val != p->val)
                return false;
            pre = pre->next;
            p = p->next;
        }
        return true;
    }
};