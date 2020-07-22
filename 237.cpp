/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prevNode = node;
        ListNode* curNode = node->next;
        
        while (curNode->next){
            prevNode->val = curNode->val;
            prevNode = curNode;
            curNode = curNode->next;
        }
        
        prevNode->val = curNode->val;
        prevNode->next = nullptr;
        delete curNode;
    }
};
