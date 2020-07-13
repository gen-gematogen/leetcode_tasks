class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* last;
        ListNode* prev;

        last = head;

        for (int i = 0; i < n; ++i){
            last = last->next;
        }

        prev = head;

        if (last != nullptr){
            while(last->next){
                last = last->next;
                prev = prev->next;
            }

            last = prev->next;
            prev->next = prev->next->next;
        } else{
            last = head;
            head = head->next;
        }

        delete last;
        return head;
    }
};
