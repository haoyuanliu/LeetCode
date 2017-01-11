//Solution I
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        TreeNode* cur = NULL;
        que.push(root);
        while(!que.empty())
        {
        	int len = que.size();
        	for(int i = 0; i < len; ++i)
        	{
        		cur = que.front();
        		que.pop();
        		if(cur->left) que.push(cur->left);
        		if(cur->right) que.push(cur->right);
        	}
        	res.push_back(cur->val);
        }
        return res;
    }
};

//Solution II
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> res;
        if(root == NULL) return res;
        solve(root, res, 0);
        return res;
    }
    void solve(TreeNode* root, vector<int> &res, int depth)
    {
    	if(root == NULL) return;
    	if(depth == res.size()) res.push_back(root->val);
    	solve(root->right, res, depth+1);
    	solve(root->left, res, depth+1);
    }
};