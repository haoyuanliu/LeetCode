//Solution I
class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root == NULL) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string &data)
    {
    	if(data[0] == '#')
    	{
    		if(data.size() > 1) data = data.substr(2);
    		return NULL;
    	}
    	else
    	{
    			TreeNode* p = new TreeNode(helper(data));
    			p->left = mydeserialize(data);
    			p->right = mydeserialize(data);
    			return p;
    	}
    }
private:
	int helper(string &data)
	{
		int pos = data.find(',');
		int val = stoi(data.substr(0, pos));
		data = data.substr(pos+1);
		return val;
	}
};	

//Solution II
class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        myserialize(root, out);
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream is(data);
        return mydeserialize(is);
    }
private:
    void myserialize(TreeNode *root, ostringstream &out)
    {
        if(root)
        {
            out << root->val << " ";
            myserialize(root->left, out);
            myserialize(root->right, out);
        }
        else out << "# ";
    }
    TreeNode* mydeserialize(istringstream &data)
    {
        string val;
        data >> val;
        if(val == "#") return NULL;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = mydeserialize(data);
        root->right = mydeserialize(data);
        return root;
    }
};