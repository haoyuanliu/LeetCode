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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
		vector<vector<int>> res;
		vector<int> temp;
		queue<TreeNode*> que;
		if(root == NULL)
			return res;
		int count = 0;
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
			if((count++)&1)
				reverse(temp.begin(), temp.end());
			res.push_back(temp);
		}
		return res;        
    }
};