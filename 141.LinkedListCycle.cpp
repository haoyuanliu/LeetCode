class Solution
{
    public:
        bool hasCycle(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;
            while(slow && fast)
            {
                slow = slow->next;
                if(fast->next)
                    fast = fast->next->next;
                else
                    return false;
                if(slow == fast)
                    return true;
            }
            return false;
        }
};
