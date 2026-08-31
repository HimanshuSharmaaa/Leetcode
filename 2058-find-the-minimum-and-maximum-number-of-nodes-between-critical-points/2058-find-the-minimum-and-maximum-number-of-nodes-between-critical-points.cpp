class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next->next) return {-1,-1};

        int prev = head->val, curr = head->next->val, next, mi = INT_MAX, ma, len = 0;
        ListNode* temp = head->next->next;
        vector<int> points;

        while(temp) {
            next = temp->val;
            if(prev < curr && curr > next) points.push_back(len);
            if(prev > curr && curr < next) points.push_back(len);

            temp = temp->next;
            prev = curr;
            curr = next;
            len++;
        }

        if(points.size() < 2) return {-1,-1};
        for(int i = 1; i < points.size(); i++) {
            if(i == points.size()-1) ma = points[i] - points[0];
            mi = min(mi, points[i] - points[i-1]);
        }

        return {mi, ma};
    }
};