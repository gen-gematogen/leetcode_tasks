class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        ListNode* prev = nullptr;
        
        while (l1  && l2){
            if (l1->val < l2->val){
                cur->val = l1->val;
                l1 = l1->next;
            } else{
                cur->val = l2->val;
                l2 = l2->next;
            }

            prev = new ListNode();
            
            cur->next = prev;
            prev = cur;
            cur = cur->next;
        }

        while (l1){
            cur->val = l1->val;
            l1 = l1->next;

            prev = new ListNode();
            
            cur->next = prev;
            prev = cur;
            cur = cur->next;
        }

        while(l2){
            cur->val = l2->val;
            l2 = l2->next;

            prev = new ListNode();
            
            cur->next = prev;
            prev = cur;
            cur = cur->next;
        }

        if (prev && prev->next){
            delete prev->next;
            prev->next = nullptr;
            
            return ans;
        } else{
            delete ans;
            return nullptr;
        }
    }
};
