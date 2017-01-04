/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
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
        		temp.push_back(que.front()->val);
        		if(que.front()->left)
        			que.push(que.front()->left);
        		if(que.front()->right)
        			que.push(que.front()->right);
        		que.pop();
        	}
        	res.push_back(temp);
        }
        return res;
    }
};