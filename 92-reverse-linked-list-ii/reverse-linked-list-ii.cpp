class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode* temp = head;
        ListNode* leftPrev = NULL;
        int pos = 1;

        while(pos < left){
            leftPrev = temp;
            temp = temp->next;
            pos++;
        }

        ListNode* curr = temp;
        ListNode* revPrev = NULL;

        int times = right - left + 1;

        while(times--){
            ListNode* next = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = next;
        }

        temp->next = curr;

        if(leftPrev != NULL){
            leftPrev->next = revPrev;
            return head;
        }

        return revPrev;
    }
};
