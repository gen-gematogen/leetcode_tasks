class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflow = 0;
        ListNode* root = new ListNode();
        ListNode* prev = nullptr;
        ListNode* cur = root;

        while (l1 && l2){
            cur->val = l1->val + l2->val + overflow;
            overflow = cur->val / 10;
            cur->val %= 10;

            prev = cur;
            l1 = l1->next;
            l2 = l2->next;

            cur = new ListNode();
            prev->next = cur;
        }

        while (l2){
            cur->val = l2->val + overflow;
            overflow = cur->val / 10;
            cur->val %= 10;

            prev = cur;
            l2 = l2->next;

            cur = new ListNode();
            prev->next = cur;
        }

        while (l1){
            cur->val = l1->val + overflow;
            overflow = cur->val / 10;
            cur->val %= 10;

            prev = cur;
            l1 = l1->next;

            cur = new ListNode();
            prev->next = cur;
        }

        if (overflow){
            cur->val = overflow;
        } else{
            prev->next = nullptr;
            delete cur;
        }

        return root;
    }
};
