//Solution I
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
        	return;
        stack<TreeNode*> st;
        TreeNode* p = root;
        if(p->right) st.push(p->right);
        if(p->left) st.push(p->left);
        while(!st.empty())
        {
        	p->left = NULL;
        	p->right = st.top();
        	p = p->right;
        	TreeNode* temp = st.top();
        	st.pop();
        	if(temp->right) st.push(temp->right);
        	if(temp->left) st.push(temp->left);
        }
    }
};

//Solution II
class Solution 
{
private:
	TreeNode* pre = NULL;
public:
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
        	return;
   		flatten(root->right);
   		flatten(root->left);
   		root->right = pre;
   		root->left = NULL;
   		pre = root;
    }
};


//Solution III
class Solution 
{
public:
    void flatten(TreeNode* root) 
    {
        while(root)
        {
        	if(root->left && root->right)
        	{
        		TreeNode* l = root->left;
        		while(l->right)
        			l = l->right;
        		l->right = root->right;
        	}
        	if(root->left)
        		root->right = root->left;
        	root->left = NULL;
        	root = root->right;
        }
    }
};
