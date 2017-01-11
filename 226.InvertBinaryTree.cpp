//Solution I
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL) return NULL;
    	root->left = invertTree(root->left);
    	root->right = invertTree(root->right);
    	swap(root->left, root->right);
        return root;
    }
};

//Solution II
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL) return NULL;
    	stack<TreeNode*> s;
    	s.push(root);
    	while(!s.empty())
    	{
    		TreeNode* cur = s.top();
    		s.pop();
    		if(cur)
    		{
	    		s.push(cur->left);
	    		s.push(cur->right);
	    		swap(cur->left, cur->right);
	    	}
    	}
    	return root;
    }
};