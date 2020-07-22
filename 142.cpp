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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head->next, *fast = head->next->next;
        
        while(fast){
            if (fast == slow) break;
            
            if (fast->next){
                fast = fast->next->next;
                slow = slow->next;
            } 
            else return nullptr;
        }
        
        if (!fast) return nullptr;
        
        ListNode* inters = head;
        
        while (inters != fast){
            fast = fast->next;
            inters = inters->next;
        }
        
        return inters;
    }
};
