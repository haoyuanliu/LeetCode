//Solution I
class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
    	if(root == NULL) return NULL;
        if(root->val == key)
        {
        	if(root->left)
        	{
        		TreeNode* p = root->left;
        		while(p->right) p = p->right;
        		p->right = root->right;
        		return root->left;
        	}
        	else if(root->right)
        		return root->right;
        	else return NULL;
        }
        if(root->val > key)
        	root->left = deleteNode(root->left, key);
        if(root->val < key)
        	root->right = deleteNode(root->right, key);
        return root;
    }
};

//Solution II
class Solution 
{
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
    	if(root == NULL) return NULL;
        if(root->val == key)
        {
        	if(root->right)
        	{
        		TreeNode* p = root->right;
        		while(p->left) p = p->left;
        		p->left = root->left;
        		return root->right;
        	}
        	else if(root->left)
        		return root->left;
        	else return NULL;
        }
        if(root->val > key)
        	root->left = deleteNode(root->left, key);
        if(root->val < key)
        	root->right = deleteNode(root->right, key);
        return root;
    }
};