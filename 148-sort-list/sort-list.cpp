class Solution {
public:


    ListNode* merge(ListNode* left, ListNode* right) {

        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        ListNode* head = NULL;
        ListNode* temp = NULL;

        if (left->val <= right->val) {
            head = left;
            left = left->next;
        }
        else {
            head = right;
            right = right->next;
        }

        temp = head;

        while (left && right) {

            if (left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }


        if (left)
            temp->next = left;
        else
            temp->next = right;

        return head;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }


        prev->next = NULL;

       
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);


        return merge(left, right);
    }
};