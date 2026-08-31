class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head->next->next) return {-1, -1};

        ListNode* temp = head->next->next;
        int prev = head->val, curr = head->next->val, next, mi = INT_MAX, ma,
            len = 0, fc = -1, cc = -1;

        while (temp) {
            if (prev < curr && curr > temp->val ||
                prev > curr && curr < temp->val) {
                if (fc == -1) fc = len;
                if(cc != -1) mi = min(mi, len - cc);
                cc = len;
            }

            prev = curr;
            curr = temp->val;
            temp = temp->next;
            len++;
        }

        if (mi == INT_MAX)
            return {-1, -1};
        return {mi, cc - fc};
    }
};