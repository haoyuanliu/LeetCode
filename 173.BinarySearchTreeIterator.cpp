
class BSTIterator 
{
	stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) 
    {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
     	TreeNode* temp = s.top();
     	s.pop();
     	pushAll(temp->right);
     	return temp->val;   
    }
private:
	void pushAll(TreeNode* node)
	{
		for(; node != NULL; s.push(node), node = node->left);
	}
};