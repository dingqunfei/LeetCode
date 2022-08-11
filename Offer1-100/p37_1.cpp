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
public:
    string sep = ",";
    string nul = "#";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        {
            return nul+sep;
        }
        return serialize(root->left)+serialize(root->right)+to_string(root->val)+sep;
    }

    TreeNode* deserialize(stack<string>& nodes)
    {
        string str = nodes.top();
        nodes.pop();
        if(str == "#")
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(str));
        root->right = deserialize(nodes);
        root->left = deserialize(nodes);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<string> nodes;
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
// Codec codec;
// codec.deserialize(codec.serialize(root));