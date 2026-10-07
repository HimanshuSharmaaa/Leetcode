class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(in.begin(), in.end());
        pq.push(-1);

        for(int i = 0; i < in.size(); i++) {
            if(pq.top() < in[i][0]) {
                pq.pop();
                pq.push(in[i][1]);
            } else pq.push(in[i][1]);
        }

        return pq.size();
    }
};