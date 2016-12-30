//Solution I
class Solution
{
    public:
        TreeNode *sortedListToBST(ListNode *head)
        {
            if(head == NULL)
                return NULL;
            int len = 0;
            ListNode *p = head;
            while(p)
            {
                len++;
                p = p->next;
            }
            return dfs(head, 1, len);
        }

        TreeNode *dfs(ListNode *head, int left, int right)
        {
            if(left == right)
            {
                TreeNode *root = new TreeNode(head->val);
                return root;
            }
            if(left > right)
                return NULL;
            ListNode *temp = head;
            int mid = (left + right + 1) / 2;
            for(int i = left; i < mid; ++i)
                temp = temp->next;
            TreeNode *root = new TreeNode(temp->val);
            root->left = dfs(head, left, mid-1);
            root->right = dfs(temp->next, mid+1, right);
            return root;
        }
};

//Solution II
class Solution
{
    public:
        TreeNode *sortedListToBST(ListNode *head)
        {
            if(head == NULL)
                return NULL;
            return toTree(head, NULL);
        }
        TreeNode *toTree(ListNode *head, ListNode *tail)
        {
            if(head == tail)
                return NULL;
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast != tail && fast->next != tail)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            TreeNode *res = new TreeNode(slow->val);
            res->left = toTree(head, slow);
            res->right = toTree(slow->next, tail);
            return res;
        }
};