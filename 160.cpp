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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* A_cur = headA, *B_cur = headB;

        while (A_cur){
            A_cur = A_cur->next;
            lenA++;
        }

        while (B_cur){
            B_cur = B_cur->next;
            lenB++;
        }

        A_cur = headA;
        B_cur = headB;

        while(lenA - lenB > 0){
            A_cur = A_cur->next;
            lenA--;
        }

        while(lenB - lenA > 0){
            B_cur = B_cur->next;
            lenB--;
        }

        while (A_cur != nullptr && B_cur != nullptr){
            if (A_cur == B_cur){
                return A_cur;
            }

            A_cur = A_cur->next;
            B_cur = B_cur->next;
        }

        return nullptr;
    }
};
