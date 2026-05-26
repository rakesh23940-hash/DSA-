class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* Last = head;
        int n = 1;

        while(Last->next != NULL){
            n++;
            Last = Last->next;
        }

        k = k % n;

        if(k == 0){
            return head;
        }

        int count = 1;
        ListNode* t = head;

        while(t != NULL){
            if(count == (n - k))
                break;

            count++;
            t = t->next;
        }

        Last->next = head;

        ListNode* res = t->next;

        t->next = NULL;

        return res;
    }
};