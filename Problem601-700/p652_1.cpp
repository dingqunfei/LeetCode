/**
 * @file p652_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-05
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-05
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */

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
    map<string, int> memo;
    vector<TreeNode *> res;
    string traverse(TreeNode *root)
    {
        if(!root)
        {
            return "#";
        }
        string leftStr = traverse(root->left);
        string rightStr = traverse(root->right);

        string str = leftStr + "," + rightStr + "," + to_string(root->val);
        if(memo.count(str)==0)
        {
            memo.insert(pair<string, int>(str, 1));
        }
        else if((memo.count(str) == 1) && (memo[str] == 1))
        {
            memo[str] = 2;
            res.push_back(root);
        }
        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }
};