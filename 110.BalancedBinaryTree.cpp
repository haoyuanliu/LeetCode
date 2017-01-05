//Solution I
class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
        	return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) > 1)
        	return false;
        else
        	return isBalanced(root->left) &&  isBalanced(root->right);
    }
    int getHeight(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};

//Solution II
class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
    	return getHeight(root) != -1;
    }
    int getHeight(TreeNode* root)
    {
    	if(root == NULL)
    		return 0;
    	int left = getHeight(root->left);
    	if(left == -1) return -1;
    	int right = getHeight(root->right);
    	if(right == -1) return -1;

    	if(abs(left - right) > 1) return -1;

    	return max(left, right) + 1;
    }
};
