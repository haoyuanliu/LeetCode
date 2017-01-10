class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
    	int res = (1<<31);
        if(root == NULL) return 0;
        getMax(root, res);
        return res;
    }

    int getMax(TreeNode* root, int &res)
    {
    	if(root == NULL) return 0;
    	int left = max(0, getMax(root->left, res));
    	int right = max(0, getMax(root->right, res));
    	res = max(res, left + right + root->val);
    	return root->val + max(left, right);
    }
};
