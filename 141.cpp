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
    bool hasCycle(ListNode *head) {
        if (head == nullptr){
            return false;
        }

        ListNode* next;
        ListNode* cur = head;

        while (cur->next != nullptr && cur->next->next != head){
            next = cur->next;
            cur->next = head;
            cur = next;
        }

        if (cur->next == nullptr){
            return false;
        } 

        return true;
    }
};
