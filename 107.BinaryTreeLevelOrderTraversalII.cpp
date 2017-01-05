class Solution 
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        if(root == NULL)
        	return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
        	temp.clear();
        	int len = que.size();
        	for(int i = 0; i < len; ++i)
        	{
        		if(que.front()->left)
        			que.push(que.front()->left);
        		if(que.front()->right)
        			que.push(que.front()->right);
        		temp.push_back(que.front()->val);
        		que.pop();
        	}
        	res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};