#include <iostream>
#include <vector>
using namespace std;
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        midOrder(res, root);
        return res;
    }

    void midOrder(vector<int> &res, TreeNode *root)
    {
        if(root)
        {
            midOrder(res, root->left);
            res.push_back(root->val);
            midOrder(res, root->right);
        }
    }
};
