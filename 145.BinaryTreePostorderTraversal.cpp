//Solution I
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
    	vector<int> res;
    	if(root == NULL) return res;
        stack<TreeNode*> s;
        TreeNode *pre = NULL;
        TreeNode *cur = NULL;
        s.push(root);
        while(!s.empty())
        {
        	cur = s.top();
        	if((!cur->left && !cur->right) 
        		|| (pre && (cur->left == pre || cur->right == pre)))
        	{
        		res.push_back(cur->val);
        		s.pop();
        		pre = cur;
        	}
        	else
        	{
        	    if(cur->right) s.push(cur->right);
        		if(cur->left) s.push(cur->left);
        	}
        }
        return res;
    }
};


//Solution II
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        TreeNode *cur = NULL;
        s.push(root);
        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if(cur->left) s.push(cur->left);
            if(cur->right) s.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};