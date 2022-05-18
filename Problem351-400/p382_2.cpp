/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> vecPNode;
    int count;
    Solution(ListNode* head) {
        while(head)
        {
            vecPNode.push_back(head);
            head = head->next;
        }
        count = vecPNode.size();
    }
    
    int getRandom() {
        int index = rand()%count;
        return vecPNode[index]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */