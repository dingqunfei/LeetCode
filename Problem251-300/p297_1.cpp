/**
 * @file p297_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-11
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serialize(TreeNode *root, string &res)
    {
        if(!root)
        {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ",";
        serialize(root->left, res);
        serialize(root->right, res);
    }

    TreeNode* deserialize(queue<string> &nodes)
    {
        string node_str = nodes.front();
        nodes.pop();
        if(node_str == "#")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(node_str));
        root->left = deserialize(nodes);
        root->right = deserialize(nodes);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        int i = 0, j = 0;
        while (i < data.size())                 //以逗号分割字符串，存入队列q中
        {
            while (data[i] != ',' && i < data.size()) 
            {
                i ++ ;
            }
            string tmp = data.substr(j, i - j);
            nodes.push(tmp);
            i ++ ;
            j = i;
        }
        return deserialize(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));