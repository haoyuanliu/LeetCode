class Solution 
{
public:
	int res = 0;
    int sumOfLeftLeaves(TreeNode* root) 
    {
    	if(root == NULL) return 0;
    	int res = 0;
    	if(root->left)
    	{
    		if(!root->left->left && !root->left->right)
    			res += root->left->val;
    		else
    			res += sumOfLeftLeaves(root->left);
    	}
    	res += sumOfLeftLeaves(root->right);
    	return res;
    }
};

class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
    	int res = 0;
    	if(root == NULL) return res;
    	stack<TreeNode*> s;
    	s.push(root);
    	while(!s.empty())
    	{
    		TreeNode* p = s.top();
    		s.pop();
    		if(p->left)
    		{
    			if(!p->left->left && !p->left->right)
    				res += p->left->val;
    			else
    				s.push(p->left);
    		}
    		if(p->right)
    		{
    			if(p->right->left || p->right->right)
    				s.push(p->right);
    		}
    	}
    	return res;
    }
};