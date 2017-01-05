class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {

     	  TreeNode* root = solve(preorder, inorder, 0, preorder.size(), 0, preorder.size());
     	  return root;
    }
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int s, int e)
    {
    	if(end == start || end < start)
    		return NULL;
    	if(end - start == 1)
    	{
    		return new TreeNode(preorder[start]);
    	}
    	else
    	{
    		TreeNode* res = new TreeNode(preorder[start]);
    		int mid;
    		for(int i = s; i < e; ++i)
    		{
    			if(inorder[i] == preorder[start])
    			{
    				mid = i;
    				break;
    			}
    		}
    		res->left = solve(preorder, inorder, start+1, start+mid-s+1, s, mid);
    		res->right = solve(preorder, inorder, start+mid-s+1, end, mid+1, e);
    		return res;
    	}
    	return NULL;
    }
};