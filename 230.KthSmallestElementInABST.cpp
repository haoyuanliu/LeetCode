//Solution I
class Solution 
{
public:
	int count = 0;
	int res;
    int kthSmallest(TreeNode* root, int k) 
    {
    	inOrder(root, k);
    	return res;
    }
    void inOrder(TreeNode* root, int k)
    {
    	if(root == NULL) return;
    	inOrder(root->left, k);
    	if(++count == k)
    	{
    		res = root->val;
    		return;
    	}
    	inOrder(root->right, k);
    }
};

//Solution II
class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
    	stack<TreeNode*> s;
    	int count = 0;
    	TreeNode* p = root;
    	while(!s.empty() || p)
    	{
    		while(p)
    		{
    			s.push(p);
    			p = p->left;
    		}
    		p = s.top();
    		s.pop();
    		if(++count == k)
    			return p->val;
    		p = p->right;
    	}
    	return 0;
    }
};