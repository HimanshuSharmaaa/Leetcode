class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()) {
            auto [data, node] = pq.top();
            pq.pop();
            if(node->next) pq.push({node->next->val, node->next});
            dummy->next = node;
            dummy = dummy->next;
        }

        return head->next;
    }
};