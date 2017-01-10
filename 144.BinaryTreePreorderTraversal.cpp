//Solution I
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL) return res;
        solve(res, root);
        return res;
    }
    void solve(vector<int> &res, TreeNode* root)
    {
    	if(root == NULL) return;
    	res.push_back(root->val);
    	solve(res, root->left);
    	solve(res, root->right);
    }
};

//Solution II
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty())
        {
        	while(p)
        	{
        		res.push_back(p->val);
        		s.push(p);
        		p = p->left;
        	}
        	if(!s.empty())
        	{
        		p = s.top();
        		s.pop();
        		p = p->right;
        	}
        }
        return res;
    }
};