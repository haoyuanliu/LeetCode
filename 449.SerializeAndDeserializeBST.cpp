class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        ostringstream out;
        mySerialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        istringstream in(data);
    }
private:
	void mySerialize(TreeNode* root, ostringstream &out)
	{
		if(root == NULL) return;
		mySerialize(root->left, out);
		out << root->val << " ";
		mySerialize(root->right, out);
	}
	TreeNode* myDeserialize(istringstream &in)
	{
		string val;
		in >> val;
		TreeNode *root = new TreeNode(stoi(val));
		while(!in.empty())
		{
			
		}
	}
};
