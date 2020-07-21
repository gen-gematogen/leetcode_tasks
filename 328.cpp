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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }

        ListNode* rootEven = head->next;
        ListNode* curOdd = head;
        ListNode* curEven = head->next;

        while (curOdd->next && curEven->next){
            curOdd->next = curOdd->next->next;
            curEven->next = curEven->next->next;
            
            curOdd = curOdd->next;
            curEven = curEven->next;
        }

        curOdd->next = rootEven;

        return head;
    }
};
