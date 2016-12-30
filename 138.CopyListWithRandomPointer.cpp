/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution 
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {
        if(head == NULL)
            return NULL;
        RandomListNode *p = head;
        RandomListNode *cp;
        RandomListNode *res;
        while(p)
        {
            cp = new RandomListNode(p->label);
            cp->next = p->next;
            p->next = cp;
            p = cp->next;
        }
        p = head;
        while(p)
        {
            cp = p->next;
            if(p->random)
                cp->random = p->random->next;
            p = cp->next;
        }
        res = head->next;
        p = head;
        while(p)
        {
            cp = p->next;
            p->next = cp->next;
            p = p->next;
            if(p)
                cp->next = p->next;
        }
        return res;
    }
};