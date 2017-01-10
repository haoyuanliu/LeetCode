Solution I
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if(root == NULL)
            return;
        queue<TreeLinkNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeLinkNode* p = que.front();
            int len = que.size();
            for(int i = 0; i < len; ++i)
            {

                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                que.pop();
                if(i < len-1)
                {
                    p->next = que.front();
                    p = p->next;
                }               
            }
            p->next = NULL;
        }
    }
};

//Solution II
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if(root == NULL)
            return;
        TreeLinkNode* head = NULL;
        TreeLinkNode* pre = NULL;
        TreeLinkNode* cur = root;
        while(cur)
        {
            while(cur)
            {
                if(cur->left)
                {
                    if(!head)
                        head = cur->left;
                    else
                        pre->next = cur->left;
                    pre = cur->left;
                }
                if(cur->right)
                {
                    if(!head)
                        head = cur->right;
                    else
                        pre->next = cur->right;
                    pre = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = pre = NULL;
        }
    }
};