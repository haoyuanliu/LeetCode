//Solution I
#include <iostream>
#include <queue>
using namespace std;
struct TreeLinkNode 
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
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

int main()
{
	Solution demo;
	TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
	demo.connect(root);
    TreeLinkNode *p = root;
    while(p)
    {
        TreeLinkNode* temp = p;
        while(temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        p = p->left;
    }
	return 0;
}

//Solution II
class Solution 
{
public:
    void connect(TreeLinkNode *root) 
    {
        if(root == NULL) return;
        TreeLinkNode* pre = root;
        TreeLinkNode* cur = NULL;
        while(pre->left)
        {
            cur = pre;
            while(cur)
            {
                cur->left->next = cur->right;
                if(cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
    }
};