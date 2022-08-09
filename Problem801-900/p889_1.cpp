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
    TreeNode* build(vector<int>::iterator preleft, vector<int>::iterator preright, vector<int>::iterator postleft, vector<int>::iterator postright)
    {
        if(preleft >= preright)
        {
            return nullptr;
        }
        int val = *preleft;
        TreeNode* root = new TreeNode(val);
        if(preleft + 1 >= preright)
        {
            return root;
        }

        int bound = *(preleft + 1);
        auto index = find(postleft, postright-1, bound);
        int left_size = index - postleft + 1;
        root->left = build(preleft+1, preleft+left_size+1, postleft, postleft+left_size);
        root->right = build(preleft+left_size+1, preright, postleft+left_size, postright-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder.begin(), preorder.end(), postorder.begin(), postorder.end());
    }
};