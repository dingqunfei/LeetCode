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
    unordered_map<string, int> mStringNum;
    vector<TreeNode*> res;
    string traverse(TreeNode* root)
    {
        if(root == NULL)
        {
            return string("#,");
        }
        string left = traverse(root->left);
        string right = traverse(root->right);
        string curr = left + right + to_string(root->val) + string(",");
        if(mStringNum.count(curr) == 0)
        {
            mStringNum[curr] = 1;
        }
        else if(mStringNum[curr] == 1)
        {
            res.push_back(root);
            mStringNum[curr] += 1;
        }
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }
};