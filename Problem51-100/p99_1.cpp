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
    vector<TreeNode*> pNodeVec;
    void midOrder(TreeNode* root)
    {
        if(root)
        {
            midOrder(root->left);
            pNodeVec.push_back(root);
            midOrder(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        midOrder(root);
        int n = pNodeVec.size();
        int left = 0, right = 0;
        bool leftNode = false, rightNode = false;
        int prev = pNodeVec[0]->val;
        for(int i = 0; i < n; ++i)
        {
            int cur = pNodeVec[i]->val;
            if(cur < prev)
            {
                if(!leftNode)
                {
                    leftNode = true;
                    left = i-1;
                }
                else if(!rightNode)
                {
                    rightNode = true;
                    right = i;
                }
            }
            prev = cur;
        }
        if(rightNode && leftNode)
        {
            int temp = pNodeVec[left]->val;
            pNodeVec[left]->val = pNodeVec[right]->val;
            pNodeVec[right]->val = temp;
        }
        else
        {
            int temp = pNodeVec[left]->val;
            pNodeVec[left]->val = pNodeVec[left+1]->val;
            pNodeVec[left+1]->val = temp;
        }
        
    }
};