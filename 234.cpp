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
    ListNode* l;
    
    bool isPalindrome(ListNode* head) {
        l = head;
        
        return check(head);
    }
    
    bool check(ListNode* r){
        if (!r) return true;
        
        bool res = check(r->next) && (r->val == l->val);
        l = l->next;
        
        return res;
    }
};
