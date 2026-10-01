class Solution {
public:
    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;

        while(left && right) {
            if(left->val <= right->val) {
                dummy->next = left;
                left = left->next;
            } else {
                dummy->next = right;
                right = right->next;
            }

            dummy= dummy->next;
        }

        if(left) dummy->next = left;
        else dummy->next = right;
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* slow = head, *fast = head->next;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* right = slow->next;
        slow->next = NULL;

        head = sortList(head);
        right = sortList(right);

        return mergeList(head, right);
    }
};