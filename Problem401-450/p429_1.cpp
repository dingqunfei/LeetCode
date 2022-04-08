/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levelAns;
        if(!root)
        {
            return levelAns;
        }
        queue<Node *> nodes;
        nodes.push(root);
        int nPrevLevelElem = 0;
        Node* temp = NULL;
        while(!nodes.empty())
        {
            nPrevLevelElem = nodes.size();
            vector<int> level;
            for(int i = 0; i < nPrevLevelElem; ++i)
            {
                temp = nodes.front();
                nodes.pop();
                level.push_back(temp->val);
                for(auto child: temp->children)
                {
                    nodes.push(child);
                }
            }
            levelAns.push_back(level);
        }
        return levelAns;
    }
};