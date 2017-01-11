//Solution I TLE
class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        int res = 0;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
        	int len = que.size();
        	res += len;
        	for(int i = 0; i < len; ++i)
        	{
        		TreeNode* temp = que.front();
        		que.pop();
        		if(temp->left) que.push(temp->left);
        		if(temp->right) que.push(temp->right);
        	}
        }
        return res;
    }
};


//Solution II 
class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        int h = getHeight(root);
        return h < 0 ? 0 : getHeight(root->right) == h-1 ? (1<<h) + countNodes(root->right) : (1<<h-1) + countNodes(root->left);
    }
    int getHeight(TreeNode* root)
    {
    	return root == NULL ? -1 : 1 + getHeight(root->left);
    }
};