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
    unordered_map<int, int> index;
    TreeNode* buildByIndex(vector<int>& preorder, vector<int>& inorder, int prehead, int pretail, int inhead, int intail)
    {
        if(prehead > pretail)
        {
            return nullptr;
        }
        int root_val = preorder[prehead];
        TreeNode* root = new TreeNode(root_val);
        int root_index = index[root_val];
        int sub_pretree_num = root_index - inhead;
        root->left = buildByIndex(preorder, inorder, prehead+1, prehead+sub_pretree_num, inhead, root_index-1);
        root->right = buildByIndex(preorder, inorder, prehead+sub_pretree_num+1, pretail, root_index+1, intail);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        for(int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }
        return buildByIndex(preorder, inorder, 0, n-1, 0, n-1);
    }
};