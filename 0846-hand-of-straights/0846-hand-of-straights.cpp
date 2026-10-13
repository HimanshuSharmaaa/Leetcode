class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gSize) {
        if (hand.size() % gSize != 0) return false;

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mpp;

        for (int i = 0; i < hand.size(); i++) mpp[hand[i]]++;
        for (auto& i : mpp) pq.push(i.first);

        while (!pq.empty()) {
            vector<int> replacedTasks;
            int prev;

            for (int i = 0; i < gSize; i++) {
                if (!pq.empty()) {
                    if (i > 0 && prev + 1 != pq.top()) return false;
                    prev = pq.top();
                    mpp[pq.top()]--;
    
                    if (mpp[pq.top()] == 0) mpp.erase(pq.top());
                    else replacedTasks.push_back(pq.top());

                    pq.pop();

                } else return false;
            }

            for (int i = 0; i < replacedTasks.size(); i++) pq.push(replacedTasks[i]);
        }

        return true;
    }
};