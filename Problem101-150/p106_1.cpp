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
    TreeNode* build(vector<int>::iterator inleft, vector<int>::iterator inright, vector<int>::iterator postleft, vector<int>::iterator postright)
    {
        if(inleft >= inright)
        {
            return nullptr;
        }
        int val = *(postright-1);
        TreeNode* root = new TreeNode(val);
        auto index = find(inleft, inright, val);
        int left_size = index - inleft;
        root->left = build(inleft, inleft+left_size, postleft, postleft+left_size);
        root->right = build(inleft+left_size+1, inright, postleft+left_size, postright-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());

    }
};