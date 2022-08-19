/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> build(int start, int end)
    {
        vector<TreeNode*> res;
        if(start > end)
        {
            res.push_back(nullptr);
            return res;
        }

        for(int i = start; i <= end; ++i)
        {
            vector<TreeNode*> left = build(start, i-1);
            vector<TreeNode*> right = build(i+1, end);
            for(auto item1: left)
            {
                for(auto item2: right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = item1;
                    root->right = item2;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};

