/**
 * @file p116_1.cpp
 * @brief 
 * @author dingqunfei (dqflying@gmail.com)
 * @version 1.0
 * @date 2021-04-04
 * 
 * @copyright Copyright (c) 2021 DQFLYING
 * 
 * @par :
 * 
 * 
 * Date        : 2021-04-04
 * Version     : 1.0
 * Author      : dqflying
 * Lisence     : 
 * Description : 
 * 
 * 
 * 
 * 
 */


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void connectTwo(Node *leftRoot, Node *rightRoot)
    {
        if(leftRoot && rightRoot)
        {
            leftRoot->next = rightRoot;
            connectTwo(leftRoot->left, leftRoot->right);
            connectTwo(leftRoot->right, rightRoot->left);
            connectTwo(rightRoot->left, rightRoot->right);
        }
        
    }

public:
    Node* connect(Node* root) {
        if(!root)
        {
            return root;
        }
        connectTwo(root->left, root->right);
        return root;
    }
};