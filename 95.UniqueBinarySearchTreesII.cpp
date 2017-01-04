#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode*> res;
        if(n == 0)
            return res;
        return getTree(1, n);
    }
    vector<TreeNode*> getTree(int start, int end)
    {
        vector<TreeNode*> res;
        if(start > end)
        {
            res.push_back(NULL);
            return res;
        }
        if(start == end)
        {
            res.push_back(new TreeNode(start));
            return res;
        }
        for(int i = start; i <= end; ++i)
        {
            vector<TreeNode*> left = getTree(start, i-1);
            vector<TreeNode*> right = getTree(i+1, end);
            for(const auto l : left)
            {
                for(const auto r : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
